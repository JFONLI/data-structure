#include <iostream>

using namespace std;

void merge_Sort(unsigned long long arr[], int left, int right);
void Merge(unsigned long long arr[], int left, int right, int mid);

unsigned long long count;

void merge_Sort(unsigned long long arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left+right)/2;
        merge_Sort(arr, left, mid);  //left sublist
        merge_Sort(arr, mid+1, right);   //right sublist
        Merge(arr, left, right, mid);
    }
}

void Merge(unsigned long long arr[], int left, int right, int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    unsigned long long *L = new unsigned long long [n1];
    unsigned long long *R = new unsigned long long [n2];

    for (int a=0; a<n1; a++)
        L[a] = arr[left+a];
    for (int b=0; b<n2; b++)
        R[b] = arr[mid+1+b];

    int i = 0;
    int j = 0;
    int k = left;

    while((i < n1) && (j < n2))
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
            //cout << "mid - i == " << n1-i << endl;
            count = count + (n1-i);
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (i < n2)
    {
        arr[k++] = R[j++];
    }

    delete []L;
    delete []R;

}

int main()
{
    int N;
    unsigned long long *data;

    while (cin >> N)
    {
        data = new unsigned long long [N];
        count = 0;
        for (int a=0; a<N; a++)
            cin >> data[a];

        merge_Sort(data, 0 , N-1);

        cout << count << endl;
        delete []data;
    }

}

//1	2 3	4 5	6 7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	25	26	27	28	29	30	31	32	33	34	35	36	37	38	39	40	41	42	43	44	45	46	47	48	49	50	51	52	53	54	55	56	57	58	59	60	61	62	63	64	65	66	67	68	69	70	71	72	73	74	75	76	77	78	79	80	81	82	83	84	85	86	87	88	89	90	91	92	93	94	95	96	97	98	99	100	101	102	103	104	105	106	107	108	109	110	111	112	113	114	115	116	117	118	119	120	121	122	123	124	125	126	127	128	129	130	131	132	133	134	135	136	137	138	139	140	141	142	143	144	145	146	147	148	149	150	151	152	153	154	155	156	157	158	159	160	161	162	163	164	165	166	167	168	169	170	171	172	173	174	175	176	177	178	179	180	181	182	183	184	185	186	187	188	189	190	191	192	193	194	195	196	197	198	199	200	201	202	203	204	205	206	207	208	209	210	211	212	213	214	215	216	217	218	219	220	221	222	223	224	225	226	227	228	229	230	231	232	233	234	235	236	237	238	239	240	241	242	243	244	245	246	247	248	249	250	251	252	253	254	255	256	257	258	259	260	261	262	263	264	265	266	267	268	269	270	271	272	273	274	275	276	277	278	279	280	281	282	283	284	285	286	287	288	289	290	291	292	293	294	295	296	297	298	299	300	301	302	303	304	305	306	307	308	309	310	311	312	313	314	315	316	317	318	319	320	321	322	323	324	325	326	327	328	329	330	331	332	333	334	335	336	337	338	350	340	341	342	343	344	345	346	347	348	349	339	351	352	353	354	355	356	357	358	359	360	361	362	363	364	365	366	367	368	369	370	371	372	373	374	375	376	377	378	379	380	381	382	383	384	385	386	387	388	389	390	391	392	393	394	395	396	397	398	399	400	401	402	403	404	423	406	407	408	409	410	411	412	413	414	415	416	417	418	419	420	421	422	405+OK3:PG7





