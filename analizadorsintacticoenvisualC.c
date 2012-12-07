c partial class Form1 : Form
 2 
 3     {
 4 
 5 
 6 
 7         int cont = 0;
 8 
 9         int cont1 = 0;
10 
11         int cont2 = 0;
12 
13         string prueba;
14 
15         string cadena;
16 
17         string text;
18 
19         string[] vector_letra = { "a", "A", "b", "B", "c", "C", "d", "D", "e", "E" , "f", "F", "g", "G", "h", "H", "i", "I", "j", "J", "k", "K", "l", "L", "m", "M", "n", "N", "o", "O", "p", "P", "q", "Q", "r", "R", "s", "S", "t", "T", "u", "U", "v", "V", "w", "W", "x", "X", "y", "Y", "z", "Z" };
20 
21         string[] vector_digito = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
22 
23         string[] aux = new string[1000];
24 
25         
26 
27         char[] ascii = new char[100];
28 
29             public Form1()
30 
31         {
32 
33             InitializeComponent();
34 
35             ascii_letras();
36 
37 
38 
39 
40 
41         }
42 
43         private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
44 
45         {
46 
47             System.IO.StreamReader sr = new System.IO.StreamReader(this.openFileDialog1.FileName);
48 
49             cadena = System.IO.File.ReadAllText(this.openFileDialog1.FileName);
50 
51             this.txttexto.Text = sr.ReadToEnd();
52 
53 
54 
55         }
56 
57         private void btncargar_Click(object sender, EventArgs e)
58 
59         {
60 
61             this.openFileDialog1.Filter = "archivo *.txt|*.txt";
62 
63             this.openFileDialog1.FileName = "";
64 
65             this.openFileDialog1.Title = "abrir documentos";
66 
67             this.openFileDialog1.InitialDirectory = "C:\\";
68 
69             this.openFileDialog1.ShowDialog();
70 
71 
72 
73 
74 
75 
76 
77 
78 
79         }
80 
81 
82 
83         public void capturar(string captura)
84 
85         {
86 
87 
88 
89             for (int i = 0; i < captura.Length; i++)
90 
91             {
92 
93 
94 
95                 for (int k = 0; k < aux.Length; k++)
96 
97                 {
98 
99 
100 
101                     if (captura.Substring(i, 1).Equals(aux[k]))
102 
103                     {
104 
105                         for (int j = 0; j < vector_letra.Length; j++)
106 
107                         {
108 
109                             if (captura.Substring(i, 1).Equals(vector_letra[j]))
110 
111                             {
112 
113 
114 
115                                 dataGridView1.Rows.Add(cont + 1, captura, "Es una palabra");
116 
117                                cont++;
118 
119                             }
120 
121                         }
122 
123                         for (int j = 0; j < vector_digito.Length; j++)
124 
125                         {
126 
127                             if (captura.Substring(i, 1).Equals(vector_digito[j]))
128 
129                             {
130 
131                                 dataGridView1.Rows.Add(cont + 1, captura, "Es un numero");
132 
133                                 cont++;
134 
135                             }
136 
137                           }
138 
139                         for (int j = 0; j < ascii.Length; j++)
140 
141                         {
142 
143                             if (char.Parse(captura.Substring(i, 1))==(ascii[j]))
144 
145                             {
146 
147                                 dataGridView1.Rows.Add(cont + 1, captura[i], "Es un simbolo");
148 
149                                 cont++;
150 
151                             }
152 
153 
154 
155                         }
156 
157                     }
158 
159                 }
160 
161 
162 
163             }
164 
165         }
166 
167         private void btnanalizar_Click(object sender, EventArgs e)
168 
169         {
170 
171            
172 
173             for (int i = 0; i < cadena.Length; i++)
174 
175             {
176 
177                 if (cadena[i] == ' ')
178 
179                 {
180 
181                     capturar(prueba);
182 
183                     //cont++;
184 
185                     prueba = "";
186 
187 
188 
189                 }
190 
191                 else
192 
193                 {
194 
195                     prueba = prueba + cadena[i].ToString();
196 
197                 }
198 
199 
200 
201                 if (i == cadena.Length - 1)
202 
203                     capturar(prueba);
204 
205 
206 
207             }
208 
209 
210 
211 
212 
213 
214 
215             
216 
217         }
218 
219 
220 
221         private void btnagregar_Click(object sender, EventArgs e)
222 
223         {
224 
225 
226 
227             aux[cont1] = txtanalizar.Text;
228 
229           lblleng.Text = lblleng.Text + aux[cont1] + ",";
230 
231             cont1++;
232 
233             txtanalizar.Text = "";
234 
235             txtanalizar.Focus();
236 
237             
238 
239                 //aux1=aux1+aux[cont1].ToString();
240 
241             
242 
243         }
244 
245 
246 
247         public void ascii_letras() {
248 
249             for (int i = 33; i <= 47;i++ )
250 
251             {
252 
253                 ascii[cont2] = Convert.ToChar(i);
254 
255                 cont2++;
256 
257                 
258 
259             }
260 
261 
262 
263             for (int i = 58; i <= 64; i++)
264 
265             {
266 
267                 ascii[cont2] = Convert.ToChar(i);
268 
269                 cont2++;
270 
271                
272 
273             }
274 
275             for (int i = 91; i <= 96; i++)
276 
277             {
278 
279                 ascii[cont2] = Convert.ToChar(i);
280 
281                 cont2++;
282 
283                
284 
285             }
286 
287             for (int i = 123; i <= 126; i++)
288 
289             {
290 
291                 ascii[cont2] = Convert.ToChar(i);
292 
293                 cont2++;
294 
295                 
296 
297             }
298 
299             
300 
301             
302 
303         }
304 
305         
306 
307         private void btnbuscar_Click(object sender, EventArgs e)
308 
309         {
310 
311             txttexto.SelectionBackColor = Color.White;
312 
313             int q = 0;
314 
315             int contpalabra = txtbuscar.Text.Length;
316 
317             for (int i = 1; i <= txtbuscar.Text.Length; i++) { if (contpalabra == i) { q = i-1; } }
318 
319             
320 
321          
322 
323             for (int x = 0; x < txttexto.Text.Length-q;x++ )
324 
325             {
326 
327 
328 
329                 
330 
331                 for (int y = 0; y < txtbuscar.Text.Length;y++ )
332 
333             {         
334 
335                     if (txttexto.Text.Substring(x,contpalabra).Equals(txtbuscar.Text))
336 
337                     {
338 
339                         listBox1.Items.Add("encontrado en la pos:" +( x+1));
340 
341                         txttexto.Find(txtbuscar.Text);
342 
343                        txttexto.SelectionLength=contpalabra;
344 
345                        txttexto.SelectionStart = x;
346 
347                         txttexto.SelectionBackColor = Color.Red;
348 
349                         txttexto.HideSelection = false;
350 
351                     }
352 
353                                   
354 
355                     }
356 
357                     
358 
359             }
360 
361 
362 
363            
364 
365         }
366 
367 
368 
369         private void btnreemplazar_Click(object sender, EventArgs e)
370 
371         {
372 
373             string fic = this.openFileDialog1.FileName;
374 
375             string a;
376 
377             //cadena.Replace(cadena[2].ToString, "a");
378 
379             text = a;
380 
381             System.IO.StreamWriter sw = new System.IO.StreamWriter(fic);
382 
383             sw.WriteLine(text);
384 
385             sw.Close();
386 
387             
388 
389         }
390 
391 
392 
393         private void txtbuscar_TextChanged(object sender, EventArgs e)
394 
395         {
396 
397             for (int i = 0; i < txttexto.Text.Length; i++)
398 
399             {
400 
401                 txttexto.SelectionStart = i;
402 
403                 txttexto.SelectionBackColor = Color.White;
404 
405             }
406 
407         }
408 
409 
