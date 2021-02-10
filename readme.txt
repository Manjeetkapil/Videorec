This application is fully based on CLI

So for using this application you need to have opencv 4.5 version in c++ installed via github directories

and for running this application you need to execute 
```
	./run.sh
```

So after that you will see 
=>Press 1 for Signin
=>Press 2 for Signup 
Press q to quit

so for login in the app you can use now 
user id = user
password = pass

you can register also by clicking option 2
Then after login there are you will see these options

Press 1 to record video
Press 2 to show list of recorded videos
Press 3 to record only red channel video other channels value to 0
Press 4 to record only blue channel video other channels value to 0
Press 5 to record only green channels video other channel value to 0
Press q to quit

So by pressing 1 your normal video will recorded of 10 seconds will be recorded with your red channel being extracted and applying gaussian filter of 5x5 on it and it will saved to the directory "recorded"

By pressing 3 you video will be recorded in red colour(by putting other 2 channels as 0) of duration 10 seconds with applied gaussian filter of 5x5 and will saved to directory "redrecord"

By pressing 4 you video will be recorded in blue colour(by putting other 2 channels as 0) of duration 10 seconds with applied gaussian filter of 5x5 and will saved to directory "redrecord"

By pressing 5 you video will be recorded in green colour(by putting other 2 channels as 0) of duration 10 seconds with applied gaussian filter of 5x5 and will saved to directory "redrecord"

By pressing 2 you will see 

directory section 

Press 1 to show grayscale red channel videos
Press 2 to show red channel videos other channels value to 0
Press 3 to show blue channel videos other channels value to 0
Press 4 to show green channel videos other channels value to 0
Press b to back to record section
Press q to quit

By pressing 1 you can see all your videos recorded in red channel extracted and gausian filter applied.

By pressing 2 you can see all you videos recorded in red channel with other 2 channel matrix as 0 and you can see your coloured videos.

By pressing 3 you can see all you videos recorded in blue channel with other 2 channel matrix as 0 and you can see your coloured videos.

By pressing 4 you can see all you videos recorded in green channel with other 2 channel matrix as 0 and you can see your coloured videos.

By pressing b you can get back to Record section.