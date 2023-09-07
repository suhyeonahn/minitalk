# Code a small data exchange program using UNIX signals

Rules: </br>
• You must create a communication program in the form of a client and a server. </br>
• The server must be started first. After its launch, it has to print its PID. </br>
• The client takes two parameters:  </br>
◦ The server PID.  </br>
◦ The string to send.  </br>
• The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.  </br>
• The server has to display the string pretty quickly. Quickly means that if you think
it takes too long, then it is probably too long.
1 second for displaying 100 characters is way too much!  </br>
• Your server should be able to receive strings from several clients in a row without
needing to restart.  </br>
• The communication between your client and your server has to be done only using
UNIX signals.  </br>
• You can only use these two signals: SIGUSR1 and SIGUSR2.
