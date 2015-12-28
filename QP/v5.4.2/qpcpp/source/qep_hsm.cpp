/// @file
/// @brief QP::QHsm implementation
/// @ingroup qep
/// @cond
///***************************************************************************
/// Last updated for version 5.4.0
/// Last updated on  2015-04-29
///
///                    Q u a n t u m     L e a P s
///                    ---------------------------
///                    innovating embedded systems
///
/// Copyright (C) Quantum Leaps, www.state-machine.com.
///
/// This program is open source software: you can redistribute it and/or
/// modify it under the terms of the GNU General Public License as published
/// by the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// Alternatively, this program may be distributed and modified under the
/// terms of Quantum Leaps commercial licenses, which expressly supersede
/// the GNU General Public License and are specifically designed for
/// licensees interested in retaining the proprietary status of their code.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License
/// along with this program. If not, see <http://www.gnu.org/licenses/>.
///
/// Contact information:
/// Web:   www.state-machine.com
/// Email: info@state-machine.com
///***************************************************************************
/// @endcond

#define QP_IMPL           // this is QP implementation
#include "qep_port.h"     // QEP port
#ifdef Q_SPY              // QS software tracing enabled?
    #include "qs_port.h"  // include QS port
#else
    #include "qs_dummy.h" // disable the QS software tracing
#endif // Q_SPY
#include "qassert.h"      // QP embedded systems-friendly assertions


//! helper macro to trigger internal event in an HSM
#define QEP_TRIG_(state_, sig_) \
    ((*(state_))(this, &QEP_reservedEvt_[sig_]))

//! helper macro to trigger exit action in an HSM
#define QEP_EXIT_(state_) do { \
    if (QEP_TRIG_(state_, Q_EXIT_SIG) == Q_RET_HANDLED) { \
        QS_BEGIN_(QS_QEP_STATE_EXIT, QS::priv_.smObjFilter, this) \
            QS_OBJ_(this); \
            QS_FUN_(state_); \
        QS_END_() \
    } \
} while (false)

//! helper macro to trigger entry action in an HSM
#define QEP_ENTER_(state_) do { \
    if (QEP_TRIG_(state_, Q_ENTRY_SIG) == Q_RET_HANDLED) { \
        QS_BEGIN_(QS_QEP_STATE_ENTRY, QS::priv_.smObjFilter, this) \
            QS_OBJ_(this); \
            QS_FUN_(state_); \
        QS_END_() \
    } \
} while (false)


namespace QP {

Q_DEFINE_THIS_MODULE("qep_hsm")

//****************************************************************************
enum {
    QEP_EMPTY_SIG_ = 0 //!< empty signal for internal use only
};

//***************************************************************************/
/// @description
/// Static, preallocated standard events that the QEP event processor sends
/// to state handler functions of QP::QHsm and QP::QFsm subclasses to execute
/// entry actions, exit actions, and initial transitions.
///
static QEvt const QEP_reservedEvt_[4] = {
#ifdef Q_EVT_CTOR // Is the QEvt constructor provided?
    static_cast<QSignal>(0),
    static_cast<QSignal>(1),
    static_cast<QSignal>(2),
    static_cast<QSignal>(3)
#else // QEvt is a POD (Plain Old Datatype)
    { static_cast<QSignal>(0),
      static_cast<uint8_t>(0), static_cast<uint8_t>(0) },
    { static_cast<QSignal>(1),
      static_cast<uint8_t>(0), static_cast<uint8_t>(0) },
    { static_cast<QSignal>(2),
      static_cast<uint8_t>(0), static_cast<uint8_t>(0) },
    { static_cast<QSignal>(3),
      static_cast<uint8_t>(0), static_cast<uint8_t>(0) }
#endif
};


//****************************************************************************
/// @description
/// Performs the first step of HSM initialization by assigning the initial
/// pseudostate to the currently active state of the state machine.
///
/// @param[in] initial pointer to the top-most initial state-handler
///                    function in the derived state machine
///
QHsm::QHsm(QStateHandler const initial)
  : QMsm(initial)
{
    m_state.fun = Q_STATE_CAST(&QHsm::top);
}

//****************************************************************************
/// @description
/// Executes the top-most initial transition in a HSM.
///
/// @param[in] e  pointer to the initialization event (might be NULL)
///
/// @note Must be called exactly __once__ before the QP::QHsm::dispatch().
///
void QHsm::init(QEvt const * const e) {
    QStateHandler t = m_state.fun;

    /// @pre ctor must be executed and initial tran. NOT taken
    Q_REQUIRE_ID(200, (m_temp.fun != Q_STATE_CAST(0))
                      && (t == Q_STATE_CAST(&QHsm::top)));

    // execute the top-most initial transition
    QState r = (*m_temp.fun)(this, e);

    // the top-most initial transition must be taken
    Q_ASSERT_ID(210, r == Q_RET_TRAN);

    QS_CRIT_STAT_

    // drill down into the state hierarchy with initial transitions...
    do {
        // transition entry path
        QStateHandler path[MAX_NEST_DEPTH_];

        // transition entry path index
        int_fast8_t ip = static_cast<int_fast8_t>(0);

        QS_BEGIN_(QS_QEP_STATE_INIT, QS::priv_.smObjFilter, this)
            QS_OBJ_(this);       // this state machine object
            QS_FUN_(t);          // the source state
            QS_FUN_(m_temp.fun); // the target of the initial transition
        QS_END_()

        path[0] = m_temp.fun;
        (void)QEP_TRIG_(m_temp.fun, QEP_EMPTY_SIG_);
        while (m_temp.fun != t) {
            ++ip;
            Q_ASSERT_ID(220, ip < static_cast<int_fast8_t>(Q_DIM(path)));
            path[ip] = m_temp.fun;
            (void)QEP_TRIG_(m_temp.fun, QEP_EMPTY_SIG_);
        }
        m_temp.fun = path[0];

        // retrace the entry path in reverse (desired) order...
        do {
            QEP_ENTER_(path[ip]); // enter path[ip]
            --ip;
        } while (ip >= static_cast<int_fast8_t>(0));

        t = path[0]; // current state becomes the new source
    } while (QEP_TRIG_(t, Q_INIT_SIG) == Q_RET_TRAN);

    QS_BEGIN_(QS_QEP_STATE_INIT, QS::priv_.smObjFilter, this)
        QS_OBJ_(this);       // this state machine object
        QS_FUN_(&QHsm::top); // source of initial tran (the top state)
        QS_FUN_(t);          // the new active state
    QS_END_()

    m_state.fun = t; // change the current active state
    m_temp.fun  = t; // mark the configuration as stable
}

//***************************************************************************/
/// @description
/// The QP::QHsm::top() state handler is the ultimate root of state hierarchy
/// in all HSMs derived from QP::QHsm.
///
/// @param[in] e  pointer to the event to be dispatched to the HSM
///
/// @returns Always returns #Q_RET_IGNORED, which means that the top state
///          ignores all events.
///
/// @note
/// The arguments to this state handler are not used. They are provided for
/// conformance with the state-handler function signature QP::QStateHandler.
///
QState QHsm::top(void * const, QEvt const * const) {
    return Q_RET_IGNORED; // the top state ignores all events
}

//****************************************************************************
/// @description
/// Dispatches an event for processing to a hierarchical state machine (HSM).
/// The processing of an event represents one run-to-completion (RTC) step.
///
/// @param[in] e  pointer to the event to be dispatched to the HSM
///
/// @note
/// This state machine must be initialized by calling QP::QHsm::init() exactly
/// __once__ before calling QP::QHsm::dispatch().
///
void QHsm::dispatch(QEvt const * const e) {
    QStateHandler t = m_state.fun;

    /// @pre the state configuration must be stable
    Q_REQUIRE_ID(400, t == m_temp.fun);

    QStateHandler s;
    QState r;
    QS_CRIT_STAT_

    QS_BEGIN_(QS_QEP_DISPATCH, QS::priv_.smObjFilter, this)
        QS_TIME_();              // time stamp
        QS_SIG_(e->sig);         // the signal of the event
        QS_OBJ_(this);           // this state machine object
        QS_FUN_(t);              // the current state
    QS_END_()

    // process the event hierarchically...
    do {
        s = m_temp.fun;
        r = (*s)(this, e); // invoke state handler s

        // unhandled due to a guard?
        if (r == Q_RET_UNHANDLED) {

            QS_BEGIN_(QS_QEP_UNHANDLED, QS::priv_.smObjFilter, this)
                QS_SIG_(e->sig); // the signal of the event
                QS_OBJ_(this);   // this state machine object
                QS_FUN_(s);      // the current state
            QS_END_()

            r = QEP_TRIG_(s, QEP_EMPTY_SIG_); // find superstate of s
        }
    } while (r == Q_RET_SUPER);

    // transition taken?
    if ((r == Q_RET_TRAN) || (r == Q_RET_TRAN_HIST)) {
        QStateHandler path[MAX_NEST_DEPTH_];

        path[0] = m_temp.fun; // save the target of the transition
        path[1] = t;
        path[2] = s;

        // exit current state to transition source s...
        while (t != s) {
            // exit handled?
            if (QEP_TRIG_(t, Q_EXIT_SIG) == Q_RET_HANDLED) {
                QS_BEGIN_(QS_QEP_STATE_EXIT, QS::priv_.smObjFilter, this)
                    QS_OBJ_(this);   // this state machine object
                    QS_FUN_(t);      // the exited state
                QS_END_()

                (void)QEP_TRIG_(t, QEP_EMPTY_SIG_); // find superstate of t
            }
            t = m_temp.fun; // m_temp.fun holds the superstate
        }

        int_fast8_t ip = hsm_tran(path); // take the HSM transition

        // retrace the entry path in reverse (desired) order...
        for (; ip >= static_cast<int_fast8_t>(0); --ip) {
            QEP_ENTER_(path[ip]); // enter path[ip]
        }
        t = path[0];    // stick the target into register
        m_temp.fun = t; // update the next state

        // drill into the target hierarchy...
        while (QEP_TRIG_(t, Q_INIT_SIG) == Q_RET_TRAN) {

            QS_BEGIN_(QS_QEP_STATE_INIT, QS::priv_.smObjFilter, this)
                QS_OBJ_(this);       // this state machine object
                QS_FUN_(t);          // the source (pseudo)state
                QS_FUN_(m_temp.fun); // the target of the transition
            QS_END_()

            ip = static_cast<int_fast8_t>(0);
            path[0] = m_temp.fun;
            (void)QEP_TRIG_(m_temp.fun, QEP_EMPTY_SIG_); // find superstate
            while (m_temp.fun != t) {
                ++ip;
                path[ip] = m_temp.fun;
                (void)QEP_TRIG_(m_temp.fun, QEP_EMPTY_SIG_);// find superstate
            }
            m_temp.fun = path[0];

            // entry path must not overflow
            Q_ASSERT_ID(410, ip < static_cast<int_fast8_t>(MAX_NEST_DEPTH_));

             // retrace the entry path in reverse (correct) order...
            do {
                QEP_ENTER_(path[ip]);  // enter path[ip]
                --ip;
            } while (ip >= static_cast<int_fast8_t>(0));

            t = path[0];
        }

#ifdef Q_SPY
        if (r == Q_RET_TRAN) {

            QS_BEGIN_(QS_QEP_TRAN, QS::priv_.smObjFilter, this)
                QS_TIME_();          // time stamp
                QS_SIG_(e->sig);     // the signal of the event
                QS_OBJ_(this);       // this state machine object
                QS_FUN_(s);          // the source of the transition
                QS_FUN_(t);          // the new active state
            QS_END_()

        }
        else {

            QS_BEGIN_(QS_QEP_TRAN_HIST, QS::priv_.smObjFilter, this)
                QS_TIME_();          // time stamp
                QS_SIG_(e->sig);     // the signal of the event
                QS_OBJ_(this);       // this state machine object
                QS_FUN_(s);          // the source of the transition
                QS_FUN_(t);          // the new active state
            QS_END_()

        }
#endif // Q_SPY

    }
    // transition not taken
    else {
#ifdef Q_SPY
        if (r == Q_RET_HANDLED) {

            QS_BEGIN_(QS_QEP_INTERN_TRAN, QS::priv_.smObjFilter, this)
                QS_TIME_();          // time stamp
                QS_SIG_(e->sig);     // the signal of the event
                QS_OBJ_(this);       // this state machine object
                QS_FUN_(m_state.fun);// the state that handled the event
            QS_END_()

        }
        else {

            QS_BEGIN_(QS_QEP_IGNORED, QS::priv_.smObjFilter, this)
                QS_TIME_();          // time stamp
                QS_SIG_(e->sig);     // the signal of the event
                QS_OBJ_(this);       // this state machine object
                QS_FUN_(m_state.fun);// the current state
            QS_END_()

        }
#endif
    }

    m_state.fun = t; // change the current active state
    m_temp.fun  = t; // mark the configuration as stable
}

//****************************************************************************
/// @description
/// helper function to execute transition sequence in a hierarchical state
/// machine (HSM).
///
/// @param[in,out] path array of pointers to state-handler functions
///                     to execute the entry actions
///
/// @returns the depth of the entry path stored in the @p path parameter.
////
int_fast8_t QHsm::hsm_tran(QStateHandler (&path)[MAX_NEST_DEPTH_]) {
    // transition entry path index
    int_fast8_t ip = static_cast<int_fast8_t>(-1);
    int_fast8_t iq; // helper transition entry path index
    QStateHandler t = path[0];
    QStateHandler s = path[2];
    QState r;
    QS_CRIT_STAT_

    // (a) check source==target (transition to self)
    if (s == t) {
        QEP_EXIT_(s);  // exit the source
        ip = static_cast<int_fast8_t>(0); // cause entering the target
    }
    else {
        (void)QEP_TRIG_(t, QEP_EMPTY_SIG_); // superstate of target
        t = m_temp.fun;

        // (b) check source==target->super
        if (s == t) {
            ip = static_cast<int_fast8_t>(0); // cause entering the target
        }
        else {
            (void)QEP_TRIG_(s, QEP_EMPTY_SIG_); // superstate of src

            // (c) check source->super==target->super
            if (m_temp.fun == t) {
                QEP_EXIT_(s);  // exit the source
                ip = static_cast<int_fast8_t>(0); // cause entering the target
            }
            else {
                // (d) check source->super==target
                if (m_temp.fun == path[0]) {
                    QEP_EXIT_(s); // exit the source
                }
                else {
                    // (e) check rest of source==target->super->super..
                    // and store the entry path along the way

                    // indicate that the LCA was not found
                    iq = static_cast<int_fast8_t>(0);

                    // enter target and its superstate
                    ip = static_cast<int_fast8_t>(1);
                    path[1] = t; // save the superstate of target
                    t = m_temp.fun; // save source->super

                    // find target->super->super
                    r = QEP_TRIG_(path[1], QEP_EMPTY_SIG_);
                    while (r == Q_RET_SUPER) {
                        ++ip;
                        path[ip] = m_temp.fun; // store the entry path
                        if (m_temp.fun == s) { // is it the source?
                            // indicate that the LCA was found
                            iq = static_cast<int_fast8_t>(1);

                            // entry path must not overflow
                            Q_ASSERT_ID(520,
                                ip < static_cast<int_fast8_t>(MAX_NEST_DEPTH_));
                            --ip;  // do not enter the source
                            r = Q_RET_HANDLED; // terminate the loop
                        }
                        // it is not the source, keep going up
                        else {
                            r = QEP_TRIG_(m_temp.fun, QEP_EMPTY_SIG_);
                        }
                    }

                    // LCA found yet?
                    if (iq == static_cast<int_fast8_t>(0)) {
                        // entry path must not overflow
                        Q_ASSERT_ID(510,
                            ip < static_cast<int_fast8_t>(MAX_NEST_DEPTH_));

                        QEP_EXIT_(s); // exit the source

                        // (f) check the rest of source->super
                        //                  == target->super->super...
                        //
                        iq = ip;
                        r = Q_RET_IGNORED; // indicate LCA NOT found
                        do {
                            // is this the LCA?
                            if (t == path[iq]) {
                                r = Q_RET_HANDLED; // indicate LCA found
                                // do not enter LCA
                                ip = static_cast<int_fast8_t>(
                                     iq - static_cast<int_fast8_t>(1));
                                // cause termination of the loop
                                iq = static_cast<int_fast8_t>(-1);
                            }
                            else {
                                --iq; // try lower superstate of target
                            }
                        } while (iq >= static_cast<int_fast8_t>(0));

                        // LCA not found yet?
                        if (r != Q_RET_HANDLED) {
                            // (g) check each source->super->...
                            // for each target->super...
                            //
                            r = Q_RET_IGNORED; // keep looping
                            do {
                                // exit t unhandled?
                                if (QEP_TRIG_(t, Q_EXIT_SIG) == Q_RET_HANDLED)
                                {
                                    QS_BEGIN_(QS_QEP_STATE_EXIT,
                                              QS::priv_.smObjFilter, this)
                                        QS_OBJ_(this);
                                        QS_FUN_(t);
                                    QS_END_()

                                    (void)QEP_TRIG_(t, QEP_EMPTY_SIG_);
                                }
                                t = m_temp.fun; //  set to super of t
                                iq = ip;
                                do {
                                    // is this LCA?
                                    if (t == path[iq]) {
                                        // do not enter LCA
                                        ip = static_cast<int_fast8_t>(
                                            iq - static_cast<int_fast8_t>(1));
                                        // break out of inner loop
                                        iq = static_cast<int_fast8_t>(-1);
                                        r = Q_RET_HANDLED; // break outer loop
                                    }
                                    else {
                                        --iq;
                                    }
                                } while (iq >= static_cast<int_fast8_t>(0));
                            } while (r != Q_RET_HANDLED);
                        }
                    }
                }
            }
        }
    }
    return ip;
}

//****************************************************************************
/// @description
/// Tests if a state machine derived from QHsm is-in a given state.
///
/// @note
/// For a HSM, to "be in a state" means also to be in a superstate of
/// of the state.
///
/// @param[in] state pointer to the state-handler function to be tested
///
/// @returns 'true' if the HSM is in the @p state and 'false' otherwise
///
bool QHsm::isIn(QStateHandler const s) {

    /// @pre state configuration must be stable
    Q_REQUIRE_ID(600, m_temp.fun == m_state.fun);

    bool inState = false;  // assume that this HSM is not in 'state'
    QState r;

    // scan the state hierarchy bottom-up
    do {
        // do the states match?
        if (m_temp.fun == s) {
            inState = true;    // match found, return TRUE
            r = Q_RET_IGNORED; // cause breaking out of the loop
        }
        else {
            r = QEP_TRIG_(m_temp.fun, QEP_EMPTY_SIG_);
        }
    } while (r != Q_RET_IGNORED); // QHsm_top state not reached
    m_temp.fun = m_state.fun; // restore the stable state configuration

    return inState; // return the status
}

} // namespace QP
