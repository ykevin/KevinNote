#!/bin/sh
### BEGIN INIT INFO
# Provides:          wallet print
# Required-Start:    $remote_fs
# Required-Stop:     $remote_fs
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: Start or stop the Wallet Printer service.
### END INIT INFO
case $1 in
    start)
	sudo /usr/bin/wallet
        ;;
    stop)
        killall wallet
        ;;
*)
echo "Usage: $0 (start|stop)"
;;
esac
