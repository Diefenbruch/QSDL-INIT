#
# Environment Variables for NFS-Client-Server Specification
# 

export QPAR_NUM_OF_CLIENTS=10         # Number of clients
                                      # to be created
export QPAR_LOWER_RPC_DELAY=0.2       # signal delay between
                                      # client and stub is 200 ms
export QPAR_UPPER_RPC_DELAY=0.3       # signal delay between
                                      # client and stub is 300 ms
export QPAR_LOWER_CREATION_DELAY=0.05 # lower limit for
                                      # delay between two
                                      # client creations is 0 ms
export QPAR_UPPER_CREATION_DELAY=0.1  # upper limit for
                                      # delay between two
                                      # client creations is 10 ms
export QPAR_LOWER_BYTE_SIZE=512       # lower limit for
                                      # data size in bytes
export QPAR_UPPER_BYTE_SIZE=1000000   # upper limit for
                                      # data size in bytes
export QPAR_SERVER1_NUM=1           # number of internal servers
                                      # of server1
export QPAR_SERVER1_READ=10000000    # 10 MByte / sec
export QPAR_SERVER1_WRITE=5000000    # 5 MByte / sec
export QPAR_SERVER2_NUM=1           # number of internal servers
                                      # of server2
export QPAR_SERVER2_READ=10000000    # 10 MByte / sec
export QPAR_SERVER2_WRITE=5000000    # 5 MByte / sec

