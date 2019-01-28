/******************************************************************************
 *                            blk_tcp.h
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

#ifndef _BLK_TCP_H_
#define _BLK_TCP_H_

/******************************************************************************
 * Includes
 *****************************************************************************/

#include "sys_qtcp.h"

#include <SCL/SCProcessType.h>

/******************************************************************************
 * SDL-Blockklasse
 *****************************************************************************/

class blk_tcp : protected sys_qtcp
{
  public:
    /**************************************************************************
     * Initialisierungsfunktion (statisch)
     *************************************************************************/

    static SCBoolean Initialize(void);

    /**************************************************************************
     * Beendigungsfunktion (statisch)
     *************************************************************************/

    static void Finish(void);

    /**************************************************************************
     * Prozesstypen (statisch)
     *************************************************************************/

    class PcsType_manager: public SCProcessType
    {
      public:
        PcsType_manager(SCNatural type_key, const char *type_name,
                        SCInteger max_processes, SCNatural input_queue_length) :
          SCProcessType(type_key, type_name, max_processes, input_queue_length)
        {
        }
        SCProcess *NewInstance(const SCProcessID creatorID = kSCNoProcessID,
                               SCDataType *actual_params = NULL) const;
        SCProcess *NewInstance(SCMem &save_area) const;
    };
    static PcsType_manager * pcs_type_manager;
    class PcsType_port: public SCProcessType
    {
      public:
        PcsType_port(SCNatural type_key, const char *type_name,
                     SCInteger max_processes, SCNatural input_queue_length) :
          SCProcessType(type_key, type_name, max_processes, input_queue_length)
        {
        }
        SCProcess *NewInstance(const SCProcessID creatorID = kSCNoProcessID,
                               SCDataType *actual_params = NULL) const;
        SCProcess *NewInstance(SCMem &save_area) const;
    };
    static PcsType_port * pcs_type_port;

    /**************************************************************************
     * Konstruktor
     *************************************************************************/

    blk_tcp(void);

    /**************************************************************************
     * Destruktor
     *************************************************************************/

    ~blk_tcp(void);

    /**************************************************************************
     * IDs der Prozesstypen
     *************************************************************************/

    enum
    {
      pcs_type_id_manager = kSCProcessTypeIDBase + 2,
      pcs_type_id_port
    };

};

#endif
