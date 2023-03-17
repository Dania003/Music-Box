# Music-Box
<h2>mini music box puzzle game</h2>

This puzzle is a music challenge escape room puzzle that consists of two different parts that must be solved by the user. The first part is composed of four different levels that vary in solution and difficulty, while the second part is a lock that opens with a pin number that the user would get after completing all four levels.

The game is designed to be interactive and challenging to solve, providing an engaging experience to the users. The way the game works is pretty simple; the screen on the device displays a certain pattern of notes, and the user is required to play the keys that correspond to each note displayed, depending on the given pattern, within a very limited amount of time. As the user progresses to a higher level, the allowed time would decrease, and the number of notes that must be played would increase.

After each level is successfully completed, the screen on the device displays a congratulatory message, and the user is informed about the upcoming level. When all four levels are completed successfully, another message would be displayed, providing the pin number to open the lock and collect the keys. However, if the user fails to complete a level, the screen would display a message, and the user has to restart from level 1.

For this project, we have used two LCD 1602 display modules to present the results of the user, the time allowed to complete each level, and the notes that must be played. We have programmed the STM32F401 Nucleo-64 board to calculate the time the user has to complete each task using a loop or a “time library.” The input from the user is gathered using a series of buttons that tell the puzzle which notes the player is playing. We have used CQRobot Speakers to output the sound of each note played by the user, making them audible and providing a seamless experience.

In conclusion, this puzzle is designed to provide a challenging and interactive escape room experience to the users, engaging them in a unique music challenge that tests their musical abilities. With its user-friendly and enjoyable design, it is sure to provide a fun-filled experience to the users.


<picture>
 <source media="(prefers-color-scheme: dark)" srcset="YOUR-DARKMODE-IMAGE">
 <source media="(prefers-color-scheme: light)" srcset="YOUR-LIGHTMODE-IMAGE">
 <img alt="img" src="https://raw.githubusercontent.com/Dania003/Music-Box/main/Untitled%20drawing%20(17).jpg">
</picture>
