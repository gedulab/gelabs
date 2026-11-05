savedcmd_/home/geduer/gelabs/llaolao2/llaolao2.mod := printf '%s\n'   main.o gearm.o | awk '!x[$$0]++ { print("/home/geduer/gelabs/llaolao2/"$$0) }' > /home/geduer/gelabs/llaolao2/llaolao2.mod
