<h1>
    My build of <img src="https://st.suckless.org/st.svg" alt="st">
</h1>

<p>
    The <a href="https://st.suckless.org/">suckless terminal (st)</a> with some additional patches.
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
            <td><b>&lt;Ctrl-Shift&gt; X</b></td>
            <td>Zoom in</td>
        </tr>
        <tr>
            <td><b>&lt;Ctrl-Shift&gt; Z</b></td>
            <td>Zoom out</td>
        </tr>
        <tr>
            <td><b>&lt;Ctrl-Shift&gt; H</b></td>
            <td>Reset zoom</td>
        </tr>
        <tr>
            <td><b>&lt;Ctrl&gt; y</b></td>
            <td>Copy text</td>
        </tr>
        <tr>
            <td><b>&lt;Ctrl&gt; p</b></td>
            <td>Paste text</td>
        </tr>
        <tr>
            <td><b>&lt;Ctrl&gt; k</b></td>
            <td>Scroll up one line</td>
        </tr>
        <tr>
            <td><b>&lt;Ctrl&gt; j</b></td>
            <td>Scroll down one line</td>
        </tr>
        <tr>
            <td><b>&lt;Ctrl-Shift&gt; K</b></td>
            <td>Scroll up one page</td>
        </tr>
        <tr>
            <td><b>&lt;Ctrl-Shift&gt; J</b></td>
            <td>Scroll down one page</td>
        </tr>
    </tbody>
</table>

<h2>
    Patches
</h2>

<ul>
    <li><a href="https://st.suckless.org/patches/alpha/">alpha</a>: Background opacity.</li>
    <li><a href="https://st.suckless.org/patches/anysize/">anysize</a>: Resize to any pixel size.</li>
    <li><a href="https://st.suckless.org/patches/bold-is-not-bright/">boldisnotbright</a>: Bold text is not rendered as bright.</li>
    <li><a href="https://st.suckless.org/patches/boxdraw/">boxdraw</a>: Rendering of lines/blocks/braille characters.</li>
    <li><a href="https://st.suckless.org/patches/font2/">font2</a>: Spare fonts.</li>
    <li><a href="https://st.suckless.org/patches/scrollback/">scrollback</a>: Scrollback in the terminal.</li>
    <li><a href="https://st.suckless.org/patches/xresources/">xresources</a>: Color and font control via Xresources.</li>
</ul>

<h2>
    Install
</h2>

<pre><code>make
doas make install
</code></pre>
