<h1> 
    My build of <img src="https://dwm.suckless.org/dwm.svg" alt="dwm"> 
</h1>

<p>
    The <a href="https://dwm.suckless.org/">dynamic window manager (dwm)</a> with some additional patches.
</p>

<h2>
    Key Bindings
</h2>

<table>
    <thead>
        <tr>
            <td><b>Key binding</b></td>
            <td><b>Action</b></td>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><b>&lt;Super&gt; s</b></td>
            <td>Spawn dmenu</td>
        </tr>
        <tr>
            <td><b>&lt;Super&gt; q</b></td>
            <td>Kill client</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Shift&gt; s</b></td>
            <td>Sticky client</td>
        </tr>
        <tr>
            <td><b>&lt;Super&gt; k</b></td> 
            <td>Next client in stack</td>
        </tr>
        <tr>
            <td><b>&lt;Super&gt; j</b></td> 
            <td>Previous client in stack</td>
        </tr>
        <tr>
            <td><b>&lt;Super&gt; ,</b></td>
            <td>Move to left monitor</td>
        </tr>
        <tr>
            <td><b>&lt;Super&gt; .</b></td>
            <td>Move to right monitor</td>
        </tr>
        <tr>
            <td><b>&lt;Super&gt; {0..9}</b></td>
            <td>Move to tag</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Shift&gt; {0..9}</b></td>
            <td>Move client to tag</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Shift&gt; ,</b></td>
            <td>Move client to left monitor</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Shift&gt; .</b></td>
            <td>Move client to right monitor</td>
        </tr>
        <tr>
            <td><b>&lt;Super&gt; i</b></td> 
            <td>Increase master stack</td>
        </tr>
        <tr>
            <td><b>&lt;Super&gt; d</b></td> 
            <td>Decrease master stack</td>
        </tr>
        <tr>
            <td><b>&lt;Super&gt; l</b></td>
            <td>Increase master area</td>
        </tr>
        <tr>
            <td><b>&lt;Super&gt; h</b></td>
            <td>Decrease master area</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Shift&gt; k</b></td>
            <td>Move client position in stack forward</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Shift&gt; k</b></td>
            <td>Move client position in stack back</td>
        </tr>
        <tr>
            <td><b>&lt;Super&gt; Enter</b></td>
            <td>Promote client to master</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Shift&gt; Escape</b></td>
            <td>Kill dwm</td>
        </tr>
    </tbody>
</table>

<h2>
    Key Bindings - Layout
</h2>

<table>
    <thead>
        <tr>
            <td><b>Key binding</b></td>
            <td><b>Layout</b></td>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><b>&lt;Super-Alt&gt; t</b></td>
            <td>Classic Tile</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Alt&gt; m</b></td>
            <td>Monocle</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Alt&gt; /</b></td>
            <td>Dwindle</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Alt&gt; d</b></td>
            <td>Deck</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Alt&gt; n</b></td>
            <td>Nrow Grid</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Alt&gt; c</b></td>
            <td>Centered Master</td>
        </tr>
        <tr>
            <td><b>&lt;Super-Alt&gt; f</b></td>
            <td>Float</td>
        </tr>
    </tbody>
</table>


<h2>
    Mouse 👹
</h2>

<table>
    <thead>
        <tr>
            <td><b>Mouse Binding</b></td>
            <td><b>Action</b></td>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><b>&ltSuper&gt; left-click</b></td>
            <td>Move client</td>
        </tr>
        <tr>
            <td><b>&ltSuper&gt; right-click</b></td>
            <td>Resize client</td>
        </tr>
        <tr>
            <td><b>&ltSuper&gt; middle-click</b></td>
            <td>Toggle float client</td>
        </tr>
    </tbody>
</table>

<h2>
    Patches
</h2>

<ul>
    <li><a href="https://dwm.suckless.org/patches/hide_vacant_tags/">hide vacant tags</a>: Hide tags with no clients.</li>
    <li><a href="https://dwm.suckless.org/patches/movestack/">movestack</a>: Move clients around the stack.</li>
    <li><a href="https://dwm.suckless.org/patches/pertag/">pertag</a>: Layouts per tag.</li>
    <li><a href="https://dwm.suckless.org/patches/sticky/">sticky</a>: Make a client sticky.</li>
    <li><a href="https://dwm.suckless.org/patches/swallow/">swallow</a>: Swallow terminals spawning graphical programs.</li>
    <li><a href="https://dwm.suckless.org/patches/vanitygaps/">vanitygaps</a>: Creates gaps between windows.</li>
    <li><a href="https://github.com/ashish-yadav11/dwmblocks/blob/master/patches/dwm-dwmblocks-6.2.diff">dwmblocks</a>: Provides colored output and clickability. Needed for dwmblocks to work.</li>
    <li><a href="https://github.com/bakkeby/patches/wiki/floatpos">floatpos</a>: Control client positions when floating.</li>
</ul>

<h2>
    Install
</h2>

<pre><code>make
make install
</code></pre>
