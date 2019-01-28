/******************************************************************************
 *                            blk_application.cpp
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
#include "pcs_application_loadgenerator.h"
#include "pcs_application_applicationmanager.h"

#include <SCL/SCScheduler.h>

/******************************************************************************
 * Initialisierung der Prozesstypen und der Prozess-IDs (statisch)
 *****************************************************************************/

blk_application::PcsType_loadgenerator * blk_application::pcs_type_loadgenerator = NULL;

SCProcess *blk_application::PcsType_loadgenerator::NewInstance(const SCProcessID creatorID,
                                                               SCDataType *actual_params) const
{
  return new pcs_application_loadgenerator(creatorID, this, (PcsFormalParam_loadgenerator *)actual_params);
}

SCProcess *blk_application::PcsType_loadgenerator::NewInstance(SCMem &save_area) const
{
  return new pcs_application_loadgenerator(save_area);
}

blk_application::PcsType_applicationmanager * blk_application::pcs_type_applicationmanager = NULL;

SCProcess *blk_application::PcsType_applicationmanager::NewInstance(const SCProcessID creatorID,
                                                                    SCDataType *actual_params) const
{
  (void)actual_params;

  return new pcs_application_applicationmanager(creatorID, this);
}

SCProcess *blk_application::PcsType_applicationmanager::NewInstance(SCMem &save_area) const
{
  return new pcs_application_applicationmanager(save_area);
}


/******************************************************************************
 * Initialisierungsfunktion der SDL-Blockklasse (statisch)
 *****************************************************************************/

SCBoolean blk_application::Initialize(void)
{
  SCBoolean result = true;

  if (SCScheduler::IsVerbose())
  {
    std::cout << "Initializing block application..." << std::endl;
  }

  /****************************************************************************
   * Prozesstypen initialisieren:
   ***************************************************************************/

  pcs_type_loadgenerator = new PcsType_loadgenerator(pcs_type_id_loadgenerator,
                                                     "loadgenerator",
                                                     syn_max_connections,
                                                     kSCUnlimitedQueueLength);
  pcs_type_applicationmanager = new PcsType_applicationmanager(pcs_type_id_applicationmanager,
                                                               "applicationmanager",
                                                               1,
                                                               kSCUnlimitedQueueLength);

  /****************************************************************************
   * Statische Initialisierungsfunktionen der Prozesse aufrufen:
   ***************************************************************************/

  result = result & pcs_application_loadgenerator_data::Initialize();
  result = result & pcs_application_loadgenerator::Initialize();
  result = result & pcs_application_applicationmanager_data::Initialize();
  result = result & pcs_application_applicationmanager::Initialize();

  return result;
}

/******************************************************************************
 * Beendigungsfunktion der SDL-Blockklasse (statisch)
 *****************************************************************************/

void blk_application::Finish(void)
{
  /****************************************************************************
   * Prozesstypen zerstoeren:
   ***************************************************************************/

  delete pcs_type_loadgenerator;
  delete pcs_type_applicationmanager;

  /****************************************************************************
   * Statische Beendigungsfunktionen der Prozesse aufrufen:
   ***************************************************************************/

  pcs_application_loadgenerator_data::Finish();
  pcs_application_loadgenerator::Finish();
  pcs_application_applicationmanager_data::Finish();
  pcs_application_applicationmanager::Finish();
}

/******************************************************************************
 * Konstruktor des Blocks
 *****************************************************************************/

blk_application::blk_application(void)
{
}

/******************************************************************************
 * Destruktor des Blocks
 *****************************************************************************/

blk_application::~blk_application(void)
{
}
