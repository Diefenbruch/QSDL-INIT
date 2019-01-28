#
# setenvs for Sender-Reciever Specification
# 

setenv QPAR_MEDIUM_DELAY 2            # Medium Delay
setenv QPAR_PROCESSING_DELAY 1        # Data processing delay of sender
                                      # and receiver
setenv QPAR_LOWER_PRODUCE_DELAY 0.5   # lower produce delay
setenv QPAR_MEDIUM_PRODUCE_DELAY 1.0  # upper produce delay
setenv QPAR_UPPER_PRODUCE_DELAY 1.5   # upper produce delay

setenv QPAR_PROC_REQ_SPEED 1          # processing speed of S
                                      # for signal UDreq
setenv QPAR_PROC_REJ_SPEED 1          # processing speed of S
                                      # for signal MDrej
setenv QPAR_PROC_CON_SPEED 1          # processing speed of S
                                      # for signal MDcon
setenv QPAR_PROC_IND_SPEED 1          # processing speed of R
                                      # for signal MDind
setenv QPAR_MAX_SERVICE_RESPONSE_DELAY 1
setenv QPAR_MAX_SERVICE_PROCESSING_DELAY 1
setenv QPAR_MAX_MEDIUM_TRANSMISSION_DELAY 1
setenv QPAR_MAX_JITTER 0.5
