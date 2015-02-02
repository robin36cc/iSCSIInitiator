//
//  iSCSIQueryTarget.h
//  iSCSI_Initiator
//
//  Created by Nareg Sinenian on 1/18/15.
//
//

#ifndef __ISCSI_QUERY_TARGET_H__
#define __ISCSI_QUERY_TARGET_H__

#include "iSCSITypes.h"
#include "iSCSIPDUUser.h"

struct iSCSILoginQueryContext {
    UInt16 sessionId;
    UInt32 connectionId;
    UInt32 TSIH;
    enum iSCSIPDULoginStages currentStage;
    enum iSCSIPDULoginStages nextStage;
};

enum iSCSIRejectCode {
    kiSCSIRejectCodeTest
};



/*! Helper function used throughout the login process to query the target.
 *  This function will take a dictionary of key-value pairs and send the
 *  appropriate login PDU to the target.  It will then receive one or more
 *  login response PDUs from the target, parse them and return the key-value
 *  pairs received as a dictionary.  If an error occurs, this function will
 *  parse the iSCSI error and express it in terms of a system errno_t as
 *  the system would treat any other device.
 *  @param context the context to query (session identifier, etc)
 *  @param statusCode the iSCSI status code returned by the target
 *  @param rejectCode the iSCSI reject code, if the command was rejected
 *  @param textCmd a dictionary of key-value pairs to send.
 *  @param textRsp a dictionary of key-value pairs to receive.
 *  @return an error code that indicates the result of the operation. */
errno_t iSCSISessionLoginQuery(struct iSCSILoginQueryContext * context,
                               enum iSCSIStatusCode * statusCode,
                               enum iSCSIRejectCode * rejectCode,
                               CFDictionaryRef   textCmd,
                               CFMutableDictionaryRef  textRsp);


/*! Helper function used during the full feature phase of a connection to
 *  send and receive text requests and responses.
 *  This function will take a dictionary of key-value pairs and send the
 *  appropriate text request PDU to the target.  It will then receive one or more
 *  text response PDUs from the target, parse them and return the key-value
 *  pairs received as a dictionary.  If an error occurs, this function will
 *  parse the iSCSI error and express it in terms of a system errno_t as
 *  the system would treat any other device.
 *  @param sessionId the session identifier.
 *  @param connectionId a connection identifier.
 *  @param textCmd a dictionary of key-value pairs to send.
 *  @param textRsp a dictionary of key-value pairs to receive.
 *  @return an error code that indicates the result of the operation. */
errno_t iSCSISessionTextQuery(UInt16 sessionId,
                              UInt32 connectionId,
                              CFDictionaryRef   textCmd,
                              CFMutableDictionaryRef  textRsp);


#endif /* defined(__ISCSI_QUERY_TARGET_H__) */