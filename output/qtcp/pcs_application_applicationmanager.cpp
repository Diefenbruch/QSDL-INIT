/******************************************************************************
 *                            pcs_application_applicationmanager.cpp
 *
 * Generated by QCG in January, 28, 2019 at 13:54:45
 *           on system: raspberrypi (Linux 4.14.79-v7+ armv7l)
 *
 * User: QSDL
 *
 * Copyright (C) 1995-98 Marc Diefenbruch (md@informatik.uni-essen.de)
 *                and Joerg Ruehl (jruehl@informatik.uni-essen.de)
 *
 * All rights reserved.
 *
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/

#include "blk_application.h"
#include "blk_tcp.h"
#include "blk_ip.h"
#include "blk_medium.h"
#include "pcs_application_loadgenerator.h"
#include "pcs_application_applicationmanager.h"


#include <SCL/SCScheduler.h>
#include <SCL/SCTransition.h>

/******************************************************************************
 * Signaltypen der SDL-Timer auf Prozessebene (statisch)
 *****************************************************************************/

SCTimerType * pcs_application_applicationmanager_data::tim_type_time_between_applications = NULL;

/******************************************************************************
 * Konstanten (Synonyme) auf Prozessebene (statisch)
 *****************************************************************************/

SCInteger pcs_application_applicationmanager_data::syn_first_process_id;

/******************************************************************************
 * Typen der SDL-Zustaende auf Prozessebene (statisch)
 *****************************************************************************/

SCStateType * pcs_application_applicationmanager::state_type_start = NULL;
SCStateType * pcs_application_applicationmanager::state_type_createapplicationprocess = NULL;

/******************************************************************************
 * Input-Sets der Prozesstransitionen (statisch)
 *****************************************************************************/


/******************************************************************************
 * Initialisierungsfunktion der SDL-Prozessklasse (statisch)
 *****************************************************************************/

SCBoolean pcs_application_applicationmanager_data::Initialize(void)
{
  SCBoolean result = true;

  if (SCScheduler::IsVerbose())
  {
    SCScheduler::outputStream << "Initializing process applicationmanager..." << std::endl;
  }

  /****************************************************************************
   * Datentypen auf Prozessebene initialisieren:
   ***************************************************************************/

  syn_first_process_id = 1;

  /****************************************************************************
   * Timertypen der SDL-Timer initialisieren:
   ***************************************************************************/

  tim_type_time_between_applications = new SCTimerType(tim_type_id_time_between_applications,
                                                       "time_between_applications");


  return result;
}

SCBoolean pcs_application_applicationmanager::Initialize(void)
{
  SCNatural i;
  SCProcessID id;
  SCTransition *v_transition;
  SCBoolean result = true;

  /****************************************************************************
   * Initialisierung aller Zustaende des Prozesstyps:
   ***************************************************************************/

  state_type_start = new SCStateType(state_type_id_start, "start");
  state_type_createapplicationprocess = new SCStateType(state_type_id_createapplicationprocess,
                                                        "createapplicationprocess",
                                                        0, NULL,
                                                        false,
                                                        false,
                                                        pcs_type_applicationmanager);

  /****************************************************************************
   * Initialisierung aller Transitionen des Prozesstyps:
   ***************************************************************************/

  v_transition = new SCTransition(kSCTransitionIDBase + 0, state_type_start,
                                  -1, NULL, kSCPrioInputNone);
  assert(v_transition);
  v_transition = new SCTransition(kSCTransitionIDBase + 0, state_type_createapplicationprocess,
                                  -1, NULL, kSCPrioInputNone);
  assert(v_transition);

  /****************************************************************************
   * Initiale Anzahl von Prozessinstanzen erzeugen:
   ***************************************************************************/

  for (i = 0; i < 1; i++)
  {
    id = SCScheduler::Create(pcs_type_applicationmanager);
    assert(id != kSCNoProcessID);
  }

  return result;
}


/******************************************************************************
 * Beendigungsfunktion der SDL-Prozessklasse (statisch)
 *****************************************************************************/

void pcs_application_applicationmanager_data::Finish(void)
{
  /****************************************************************************
   * Timertypen der SDL-Timer zerstoeren:
   ***************************************************************************/

  delete tim_type_time_between_applications;

}

void pcs_application_applicationmanager::Finish(void)
{
  /****************************************************************************
   * Zustandstypen der Prozess-Zustaende zerstoeren:
   ***************************************************************************/

  delete state_type_start;
  delete state_type_createapplicationprocess;

}

/******************************************************************************
 * Konstruktoren
 *****************************************************************************/

pcs_application_applicationmanager_data::pcs_application_applicationmanager_data(void)
{
}

pcs_application_applicationmanager::pcs_application_applicationmanager(const SCProcessID creator,
                                                                       const SCProcessType *proc_type) : 
  SCProcess(creator, proc_type, state_type_start, NULL, false)
{
#if _SC_VALIDATION_OPTIMIZE
  /****************************************************************************
   * Ausgangsgroesse des Prozesses initialisieren:
   ***************************************************************************/

  SCSize my_size;

  Size(&my_size);
  SetCurrentSize(my_size.size);
  SetCurrentHistorySize(my_size.historySize);
#endif

  /****************************************************************************
   * Meldung ausgeben:
   ***************************************************************************/

  if (IsVerbose())
  {
    SCScheduler::outputStream << "Creating " << *this << std::endl;
  }

  /****************************************************************************
   * Variableninitialisierung:
   ***************************************************************************/

  v_last_process_id = 0;

  /****************************************************************************
   * Aktuellen Zustand auf Startzustand setzen:
   ***************************************************************************/

  v_cur_state = state_type_id_start;

  /****************************************************************************
   * Auf die Instanz darf nun zugegriffen werden:
   ***************************************************************************/

  GetAutomatonTable()->Insert(Self(), this);
}

pcs_application_applicationmanager::pcs_application_applicationmanager(SCMem &save_area) : 
  SCProcess(false, (SCObject *)NULL)
{
  Restore(save_area);

#if _SC_VALIDATION_OPTIMIZE
  /****************************************************************************
   * Ausgangsgroesse des Prozesses initialisieren:
   ***************************************************************************/

  SCSize my_size;

  Size(&my_size);
  SetCurrentSize(my_size.size);
  SetCurrentHistorySize(my_size.historySize);
#endif

  /****************************************************************************
   * Meldung ausgeben:
   ***************************************************************************/

  if (IsVerbose())
  {
    SCScheduler::outputStream << "Recreated " << *this << std::endl;
  }

  /****************************************************************************
   * Auf die Instanz darf nun zugegriffen werden:
   ***************************************************************************/

  GetAutomatonTable()->Insert(Self(), this);
}

/******************************************************************************
 * Destruktor
 *****************************************************************************/

pcs_application_applicationmanager_data::~pcs_application_applicationmanager_data(void)
{
}

pcs_application_applicationmanager::~pcs_application_applicationmanager(void)
{
  /****************************************************************************
   * Meldung ausgeben:
   ***************************************************************************/

  if (IsVerbose())
  {
    SCScheduler::outputStream << "Deleting " << *this << std::endl;
  }
}

/******************************************************************************
 * Implementierungsfunktion des SDL-Prozesses
 *****************************************************************************/

void pcs_application_applicationmanager::Body(void)
{
  /****************************************************************************
   * Meldung ausgeben:
   ***************************************************************************/

  if (IsVerbose())
  {
    SCScheduler::outputStream << "Executing " << *this << std::endl;
  }

  /****************************************************************************
   * Hauptschleife:
   ***************************************************************************/

  nextstate:
  v_transition_id = kSCNoTransition;
  backtracking:
  while(true)
  {
    switch(v_cur_state)
    {
      /************************************************************************
       * Starttransition:
       ***********************************************************************/

      case state_type_id_start:
        if (v_transition_id == kSCNoTransition)
        {
          v_transition_id = State(state_type_start, kSCNoAwakeDelay,
                                  &v_signal_read);
        }
        v_last_process_id = syn_first_process_id;
        v_cur_state = state_type_id_createapplicationprocess;
        goto nextstate;

      /************************************************************************
       * Zustand 'createapplicationprocess':
       ***********************************************************************/

      case state_type_id_createapplicationprocess:
        if (v_transition_id == kSCNoTransition)
        {
          v_transition_id = State(state_type_createapplicationprocess,
                                  0.0, &v_signal_read);
          if (v_cur_state != state_type_id_createapplicationprocess)
          {
            goto backtracking;
          }
        }

        /**********************************************************************
         * Transitionen des Zustands 'createapplicationprocess'
         *********************************************************************/

        switch(v_transition_id)
        {
          case kSCTransitionIDBase + 0: // Input None
            switch (v_last_process_id > syn_num_of_connections)
            {
              case true:
                Stop();
                break;
              case false:
                pcs_formal_param_loadgenerator = new PcsFormalParam_loadgenerator;
                assert(pcs_formal_param_loadgenerator);
                pcs_formal_param_loadgenerator->v_addr = v_last_process_id;
                Create(pcs_type_loadgenerator, pcs_formal_param_loadgenerator);
                v_last_process_id = v_last_process_id + 1;
                break;
            }
            v_cur_state = state_type_id_createapplicationprocess;
            goto nextstate;
            break;

          case kSCNoTransition:
            break;
          default:
            std::cerr << "State 'createapplicationprocess': Invalid transition." <<
                         std::endl;
            break;
        }
        break;

      default:
        std::cerr << "Process 'applicationmanager': Invalid process state." <<
                     std::endl;
        break;
    }
  }
}

/******************************************************************************
 * Save-Methode zur Speicherung des Prozesszustands
 *****************************************************************************/

SCBoolean pcs_application_applicationmanager::Save(SCMem &save_area) const
{
  /****************************************************************************
   * Speicherung der Daten der Basisklasse
   ***************************************************************************/

  SCProcess::Save(save_area);

  /****************************************************************************
   * Sicherung der Variablen:
   ***************************************************************************/

  save_area.Store(&v_last_process_id, sizeof(SCInteger));

  /****************************************************************************
   * Speicherung der Zustandsvariablen
   ***************************************************************************/

  save_area.Store(&v_cur_state, sizeof(v_cur_state));

  return true;
}

/******************************************************************************
 * Restore-Methode zur Restaurierung des Prozesszustands
 *****************************************************************************/

SCBoolean pcs_application_applicationmanager::Restore(SCMem &save_area)
{
  /****************************************************************************
   * Restaurierung der Daten der Basisklasse
   ***************************************************************************/

  SCProcess::Restore(save_area);

  /****************************************************************************
   * Restaurierung der Variablen:
   ***************************************************************************/

  save_area.Restore(&v_last_process_id, sizeof(SCInteger));

  /****************************************************************************
   * Restaurierung der Zustandsvariablen
   ***************************************************************************/

  save_area.Restore(&v_cur_state, sizeof(v_cur_state));

  return true;
}

/******************************************************************************
 * Size-Methode liefert benoetigten Speicherplatz
 *****************************************************************************/

void pcs_application_applicationmanager::Size(SCSize *cur_size) const
{
  /****************************************************************************
   * Berechnung der Groesse der Basisklasse
   ***************************************************************************/

  SCProcess::Size(cur_size);

  /****************************************************************************
   * Berechnung der Variablengroessen:
   ***************************************************************************/

  cur_size->size += sizeof(SCInteger);

  /****************************************************************************
   * Groesse der Zustandsvariablen
   ***************************************************************************/

  cur_size->size += sizeof(v_cur_state);

}

/******************************************************************************
 * Display-Methode
 *****************************************************************************/

SCStream& operator<<(SCStream &out, const pcs_application_applicationmanager &me)
{
  return me.Display(out);
}
