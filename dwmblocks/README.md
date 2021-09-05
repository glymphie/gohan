<h1> 
    My build of dwmblocks
</h1>

<p>
    A <a href="https://github.com/ashish-yadav11/dwmblocks">modular status monitor for dwm</a>, edited to include my public bins.
</p>

<h2>
    Usage
</h2>

<p>
    <pre><code>dwmblocks</code></pre>

In your .xinitrc
    <pre><code>exec dbus-launch --sh-syntax dwmblocks &> /tmp/dwmblocks.log &</code></pre>
</p>

<h2>
    Blocks and buttons
</h2>

<ul>
    <li><b>Currently playing</b>: Shows the currently playing song via Spotify. </li>
    <li><b>Volume info</b>: Shows the current Master volume. </li>
        <dd>- Left-click: Start Pulsemixer client window.</dd>
        <dd>- Right-click: Mute.</dd>
    <li><b>Weather</b>: Shows the weather in Copenhagen. </li>
        <dd>- Left-click: Show some more extensive weather information.</dd>
    <li><b>Ethernet connection</b>: Shows all ethernet connections. </li>
        <dd>- Left-click: Shows all interfaces with their IPs. Only the ones with operstate "UP".</dd>
    <li><b>Internet connection</b>: Shows connectivity to the internet.</li>
        <dd>- Left-click: Shows public IPv4 and IPv6.</dd>
    <li><b>Date</b>: Shows the current date.</li>
</ul>

<h2>
    Installation
</h2>

<pre><code>make
doas make install
</code></pre>
