# AI_CONTEXT.md — FXtend の全情報（AI に渡すための資料）

FXtend（効果音専用のプラグイン音源）について、**使い方、インストール、ビルド、仕組み、Windows 版の変更点、確認の状況**をまとめた資料です。この資料を AI に渡してから質問すると、書かれている内容にもとづいて、正確に答えてもらえます。

- AI の答え方のルールは、[AGENTS.md](AGENTS.md) にあります。この資料と一緒に渡してください。
- 人間向けの説明は、[README.md](README.md) です。この資料は、AI に渡すためのもので、読み物としては書いていません。
- 開発者だけのための資料ではありません。ただ使いたい人の質問にも、答えられるようにしてあります。

> **非公式です。** この資料は、作者 CHEEBOW さんのものではありません。作者の [cheebow/FXtend](https://github.com/cheebow/FXtend) をもとにした、Windows 用の非公式ビルドの管理者が、作者の README、公式の紹介ページ、作者のテスト計画（`docs/TEST_PLAN.md`）、管理者自身の確認をもとにまとめました。

## 0. 出典の印

この資料の文には、どこで確かめられた内容かを、次の印で示してあります。印が付いていない文は、その節の印と同じです。

| 印 | 意味 |
| --- | --- |
| 【作者】 | 作者の README、公式の紹介ページ、テスト計画に書かれていること。**macOS 版について**の内容です |
| 【Windows 確認】 | 管理者が、Windows 版で実際に確かめたこと |
| 【変更】 | このリポジトリで、元のソースコードや設定に加えた変更 |
| 【推測】 | 資料から推測したこと。確かではありません |

## 1. FXtend とは【作者】

曲の展開をつなぐ効果音を鳴らすためだけに作った、プラグイン音源です。Impact、Riser、Downlifter、Sweep、Clap、Sub Drop の 6 つのタイプがあります。

- 長さを「4 小節」のように決めて、MIDI ノートを 1 個置くと、曲のテンポに合わせて、狙った位置でぴたりと鳴り終わります
- 音はすべて内蔵のシンセ（Noise / Sub / FM / Transient / Clap）で作ってあり、61 種類の Factory プリセットが、追加のファイルなしですぐに使えます
- 手持ちの WAV / AIFF を 4 つまで読み込めます。鳴らし方は、Stretch、Resample、Loop、One-shot から選びます
- 鳴らしている音を、テンポも長さもそのまま、WAV ファイルに書き出せます
- プリセットと、そこで使っているサンプルを、ひとつのファイル（`.fxtendpack`）にまとめて、別のパソコンに持っていけます
- 公式の動作環境: macOS 12 以降。形式は VST3 / Audio Unit / スタンドアロンアプリ。入力は MIDI、出力はステレオ。公式の紹介ページに書かれたバージョンは 0.1.3 です
- オープンソースで、ライセンスは AGPLv3 です。Copyright © 2026 CHEEBOW

## 2. このリポジトリの立ち位置

| 項目 | 内容 |
| --- | --- |
| 元のリポジトリ | [cheebow/FXtend](https://github.com/cheebow/FXtend)。作者は CHEEBOW さん。公式版は **macOS 用**で、公式には Windows に対応していません |
| このリポジトリ | 元をもとにした、Windows 用の**非公式ビルド**。形式は **VST3 のみ**です |
| ライセンス | AGPL-3.0。JUCE 9 は AGPLv3、Rubber Band は GPL（v2 以降）の条件で使っています |
| 紹介ページ | https://cheebow.github.io/FXtend/（日本語）、https://cheebow.github.io/FXtend/en/（English） |

質問に答えるときは、**質問者が使っているのが macOS の公式版か、Windows の非公式ビルドか**で、答えが変わることがあります。

## 3. インストールとアンインストール

### macOS（公式版）【作者】

1. [最新のリリース](https://github.com/cheebow/FXtend/releases/latest) から、インストーラ（`.pkg`）をダウンロードして開きます
2. 画面の案内に沿って進みます。VST3、Audio Unit、スタンドアロンアプリの中から、入れたいものを選べます

削除するときは、次を削除します。自分で保存したプリセットと読み込んだサンプルも消すなら、最後の 1 つも削除します。

```text
/Library/Audio/Plug-Ins/VST3/FXtend.vst3
/Library/Audio/Plug-Ins/Components/FXtend.component
/Applications/FXtend.app
~/Library/Application Support/FXtend
```

### Windows（非公式ビルド）【Windows 確認】

1. このリポジトリの Releases（https://github.com/GRJaoi/FXtend/releases）から、zip をダウンロードします
2. zip を右クリック →「プロパティ」→「許可する（ブロックの解除）」にチェックを入れて OK を押します。この表示が出ないときは、そのまま次へ進みます。※この手順は Windows の一般的な仕様にもとづく説明で、管理者の環境では確かめていません
3. zip を右クリック →「すべて展開」で開きます
4. 中の `FXtend.vst3` を、**フォルダごと**、`C:\Program Files\Common Files\VST3` にコピーします。管理者の許可を求められたら、続行します
5. DAW を開き直して、プラグインを再スキャンします

注意点:

- `FXtend.vst3` は、**フォルダのまま**コピーします。中の `.vst3` ファイルだけを取り出すと、DAW が読み込めません
- zip の中に `.lib` と `.exp` が入っていますが、使いません
- コード署名がないので、SmartScreen や Defender が警告を出すことがあります
- 形式は VST3 だけです。Audio Unit（AU）は Mac だけの形式なので、Windows にはありません。スタンドアロンアプリとインストーラも、Windows 版にはありません

削除するときは、次を削除します。自分で保存したプリセットと読み込んだサンプルも消すなら、2 つ目も削除します。※削除の手順そのものは、管理者は確かめていません。

```text
C:\Program Files\Common Files\VST3\FXtend.vst3
（ユーザーの「ドキュメント」フォルダ）\CHEEBOW\FXtend
```

## 4. 使い方

### 4.1 基本の流れ【作者】

1. インストゥルメントトラックに FXtend を立ち上げて、プリセットか FX タイプを選びます
2. `LENGTH` で長さを決めます（たとえば 4 Bars）。それが何拍ぶんで何秒になるかは、すぐ横に表示されます
3. 鳴らしたい位置に MIDI ノートを 1 個置きます。ノートの高さや長さは音に関係ありません。音量はベロシティで変わります
4. `TAIL` で終わり方を選びます。`Strict` ならすぱっと無音に、`Natural` なら余韻が残ります
5. もっと作り込みたくなったら `Advanced` を開きます。`Export WAV` を押せば、ファイルに書き出せます

### 4.2 長さ・ノート・ベロシティ

- **長さ**は、小節と拍で決めます【作者】。「4 小節」と決めたら、ノートを置いた位置からきっちり 4 小節で鳴り終わります【作者】
- ノートの**長さ**は、音に関係ありません。短いノートを置いても、長いノートを置いても、終わる位置は同じです【作者】【Windows 確認】
- ノートの**高さ**（音の高低）も、音に関係ありません。ノートの高さで、音程やプリセットを変えることは、できません【作者】【Windows 確認】
- **ベロシティ**（鍵盤を押す強さ）で、音量が変わります【作者】【Windows 確認】
- ノートを拍の途中に置くと、終わる位置も、同じだけずれます【作者】【Windows 確認】
- 途中でテンポが変わっても、終わる位置はずれません【作者】【Windows 確認】
- 拍子が 6/8 のときは、`1 bar / 3 quarter notes` のように表示され、その長さで止まります【作者】

### 4.3 TAIL（終わり方）【作者】

| 設定 | 動き |
| --- | --- |
| `Strict` | 終わりの位置で、すぱっと無音になります |
| `Natural` | リバーブやディレイの響きだけが、そのあとも残ります |

Impact と Clap で、`Strict` と `Natural` の違いが聞き分けやすいです。波形プレビューに、TAIL の区間が出ます。

### 4.4 STOPPED（DAW が止まっているあいだのノートの鳴り方）【作者】

DAW を止めたまま、ピアノロールでノートを動かすと、そのたびに試聴の音が鳴ります。これが最後まで鳴り続けないように、停止中の鳴らし方を `STOPPED` で選べます。

| 設定 | 動き |
| --- | --- |
| `Gate`（初期値） | 鍵盤を押しているあいだだけ鳴ります。離すとすぐ止まります |
| `Full` | 再生中と同じように、決めた長さを最後まで鳴らします |
| `Off` | 鳴らしません |

**再生中の鳴り方は、どれを選んでも変わりません。**「最後まで聞きたい」ときは `Full`、「鳴らしたくない」ときは `Off` にします。`Preview` ボタンでも、停止中に試聴できます。

### 4.5 テンポの表示（HOST と MANUAL）

- DAW からテンポが届くときは、BPM の表示が `HOST` になります【作者】。このとき、`HOST` の数字は、DAW が決めたテンポの表示で、FXtend の側では変えられません【Windows 確認】
- スタンドアロンアプリのように、DAW からテンポが届かないときは、`MANUAL BPM` の値で鳴らします。そのあいだ、テンポの表示は `MANUAL` になります【作者】
- DAW からテンポが届いているときは、`MANUAL BPM` の欄は灰色で、値を変えても音は変わりません【Windows 確認】。壊れているのではなく、使われていないだけです

### 4.6 画面のページ

ウィンドウの大きさは変わらず、中身だけが切り替わります【作者】。

| ページ | できること |
| --- | --- |
| Presets | タイプ別に並んだ Factory プリセットと、自分で保存したプリセット。▶ を押すと、読み込む前に試聴できます【作者】 |
| Mixer | シンセ 4 つとサンプル 4 つ、それに出力の音量を、ひとつの画面で調整します【作者】 |
| Advanced | レイヤーごとの設定。On/Off、Type、音量・ピッチ・フィルターを、どこからどこへ、どんなカーブで動かすか【作者】 |
| Advanced の Master タブ | 全体にかける、トーン（フィルター）、Drive、ディレイ、リバーブ、コンプレッサー、リミッター、ステレオの広がり。メーターとクリップ表示があり、クリップ表示はクリックで消えます【作者】 |

そのほか:

- `Random`（音色をランダムに作る）を押したあと、`Undo` で戻れます【作者】。**`Undo` は、1 回分しか戻れません**【Windows 確認】。macOS 版でも同じかは、確かめていません
- Advanced のつまみは、DAW のオートメーション（つまみの動きを時間軸に書いて、自動で動かす機能）で動かせます【作者】【Windows 確認】
- 波形プレビューの上を、再生位置の線が進み、本体の終わり（Body End）で止まります【作者】
- Custom 4-point カーブは、エンジンとプリセットは対応していますが、編集する画面がまだありません【作者】
- 表示の拡大率（Windows の設定 → ディスプレイ → 拡大/縮小）を変えても、画面が崩れませんでした【Windows 確認】

### 4.7 6 つの FX タイプ【作者】

タイプごとに、ノブが 4 つあります。

| タイプ | 音の特徴 | ノブ |
| --- | --- | --- |
| Impact | ドンと一発鳴らす衝撃音。決めた長さのなかで、響きが消えていきます | Punch / Sub / Brightness / Tail |
| Riser | 終わりに向かってじわじわ盛り上がり、最後の瞬間にいちばん高まります | Rise / Tension / Brightness / Width |
| Downlifter | Riser の逆で、終わりに向かって落ちていき、最後に底へ着きます | Fall / Depth / Air / Width |
| Sweep | フィルターが動いて、ノイズが通り過ぎていくような音。風を切るような Whoosh も、ここに入っています | Direction / Cutoff Range / Noise Color / Width |
| Clap | ノイズを重ねて作るクラップ。長く尾を引く Long Clap もあります | Density / Spread / Body / Tail |
| Sub Drop | 低音がぐっと沈んでいく音。決めた音程まで下がりきったところで終わります | Start Pitch / End Pitch / Weight / Drive |

各ノブの**正確な効き方**は、作者の資料には、ノブの名前以外には書かれていません。名前から想像はできますが、断定はできません【推測】。

### 4.8 Factory プリセット【作者】

- 61 種類あります（作者のテスト計画には「30 種」とありますが、古い記述だと思われます【推測】）
- 公式の紹介ページの音の例: Impact 09 Cinematic、Riser 01 Classic Noise、Downlifter 01 Classic、Whoosh 03 Jet Flyby、Long Clap 01 Classic、Sub Drop 04 808 Dive。どれも、128 BPM・2 小節で書き出したものです
- Factory プリセットが、どのファイルにどんな形で入っているかは、資料に書かれていません

### 4.9 自分で保存するプリセット

- 自分で作った音を、プリセットとして保存できます。拡張子は `.fxpreset` で、中身は JSON（文字の形式）です【作者】
- 日本語の名前で保存しても、読み込めました【Windows 確認】

### 4.10 サンプル（手持ちの音を重ねる）

- WAV / AIFF を、スロットにドラッグ＆ドロップするか、`+ Load WAV` で読み込みます。最大 4 つです【作者】
- 日本語のファイル名、日本語のフォルダにある WAV でも、読み込めました【Windows 確認】
- 鳴らし方は 4 種類です【作者】。

| 鳴らし方 | 動き |
| --- | --- |
| Stretch | 音程はそのままに、長さだけを合わせます |
| Resample | （作者の資料に、詳しい説明はありません） |
| Loop | （同上） |
| One-shot | （同上） |

- ほかに `Trim`（切り出し）、`Reverse`（逆再生）、`Pitch`（音程）、`Mix`（混ぜる量）があります【作者】
- Stretch は、3 秒ほどの素材を 4 小節に伸ばすと、`stretching...` の表示が出て、消えてから再生すると、音程が保たれ、小節線で終わります【作者】【Windows 確認】
- 極端な長さ（たとえば 0.2 秒の素材を 8 小節）にすると、`extreme stretch` の警告が出ます【作者】【Windows 確認】
- Stretch の音は、**大きく伸ばすと、少し濁ります**【Windows 確認】。Windows では、Rubber Band（長さを変える部品）が、内蔵の FFT で動くため、macOS 版と音が違う可能性があります【作者】
- 再生中にテンポが変わると、Stretch は、終わる位置を合わせることを優先して、再生速度を変えます。そのあいだは、音程もテンポの変化ぶんだけずれます【作者】

### 4.11 サンプルの保存・復元・持ち運び

- サンプルは、読み込んだときに、FXtend の保存先の `Samples` フォルダへ**コピー**されます。プロジェクトやプリセットには、そのコピーへの参照だけが保存されます【作者】
- 元の WAV を別のフォルダへ動かしても、同じパソコンなら、変わらず鳴ります【作者】【Windows 確認】
- 保存先の `Samples` にあるコピーも消してから開くと、スロットに `Missing:` と表示されます。シンセのレイヤーは鳴ります。`Load...` で同じファイルを指定すると、元に戻ります【作者】【Windows 確認】
- 別のパソコンに持っていくときは、`File > Export Preset Package...` で、プリセットとサンプルをひとつのファイル（`.fxtendpack`）にまとめます。持っていった先で `Import Preset Package...` を使うと、サンプルごと復元されます【作者】【Windows 確認】
- 読み込むサンプルは、利用条件を確かめたうえで使います。作者の FXtend には、他人が作った音の素材は入っていません【作者】

### 4.12 WAV の書き出し【作者】

- `Export WAV` で、いま鳴らしている音を、テンポも長さもそのまま、WAV ファイルに書き出せます。オーディオトラックに貼りたいときに便利です
- 保存の形式は、24-bit / 48 kHz と、32-bit float / 96 kHz を選べます。Velocity 64 や 127 での書き出しも確認されています【Windows 確認】
- 書き出した WAV の長さは、`LENGTH` と同じです。`TAIL` が `Natural` のときは、余韻がついた長さです
- DAW へ、WAV を直接ドラッグすることは、できません。`Export WAV` で、ファイルに書き出します【作者】

### 4.13 データの保存場所

| 内容 | macOS | Windows（このリポジトリ） |
| --- | --- | --- |
| 自分で保存したプリセット | `~/Library/Application Support/FXtend/Presets` | 「ドキュメント」フォルダの `CHEEBOW\FXtend\Presets` |
| 読み込んだサンプルのコピー | `~/Library/Application Support/FXtend/Samples` | 「ドキュメント」フォルダの `CHEEBOW\FXtend\Samples` |

- Windows 版は、元の作者の版と違って、「ドキュメント」フォルダの下にまとめます【変更】。実際に、その場所にできることを確認しました【Windows 確認】
- 保存先は、`src/Storage.h` の `getAppDataDirectory()` で決めています

## 5. よくある質問と答え

| 質問 | 答え |
| --- | --- |
| ノートの長さや高さを変えても、音が変わらない。壊れている？ | 仕様です。音の長さは `LENGTH` で、音量はベロシティで決まります（4.2） |
| DAW を止めてノートを動かすと、押している間しか鳴らない | `STOPPED` が初期値の `Gate` だからです。最後まで聞くなら `Full` にします（4.4） |
| 停止中に、まったく鳴らない | `STOPPED` が `Off` かもしれません。`Gate` か `Full` にします（4.4）。DAW 側のトラックやミュートも確かめます |
| 終わる位置を、小節の頭に合わせたい | `LENGTH` を、小節の数で決めて、ノートを小節の頭に置きます（4.2） |
| `MANUAL BPM` を変えても、音が変わらない | DAW からテンポが届いているからです。値は使われていません（4.5） |
| 余韻だけ残したい | `TAIL` を `Natural` にします（4.3） |
| WAV にして、オーディオトラックで使いたい | `Export WAV` を使います（4.12） |
| サンプルのスロットに `Missing:` と出た | 保存先の `Samples` のコピーが無くなっています。`Load...` で同じファイルを指定します（4.11） |
| 別のパソコンに、音を持っていきたい | `File > Export Preset Package...` で `.fxtendpack` を作り、先で `Import Preset Package...` します（4.11） |
| Stretch で音が濁る | 大きく伸ばすと、少し濁ります。伸ばす量を減らすか、別の鳴らし方（Resample、Loop、One-shot）を試します（4.10） |
| `Undo` が 1 回しか戻らない | 管理者の確認では、1 回分だけです（4.6） |
| Windows で、DAW にプラグインが出てこない | `FXtend.vst3` を、フォルダごと `C:\Program Files\Common Files\VST3` に入れたか、DAW を再スキャンしたかを確かめます（3） |
| Windows で、ダウンロードした zip が警告される | コード署名がないためです。zip の「プロパティ」で「許可する」にチェックを入れます（3） |
| Windows 版に、スタンドアロンアプリや AU はある？ | ありません。VST3 だけです（3） |
| 作った音は、商用で使える？ | この資料には書かれていません。ソフトのライセンスは AGPLv3 ですが、書き出した音の利用条件は、資料にありません。AI は、法律の専門家ではありません |
| Cubase や Logic で動く？ | 作者の資料では、確認済みとあります（macOS 版）。Windows 版は、Fender Studio Pro 8.0.3 だけで確認しています（10） |

## 6. 仕組み（時間の扱い）【作者】

- ノートの長さは、音に関係ありません。終わる位置は、ノートを置いた位置から、`LENGTH` で決めた長さのあとの、ぴったりのサンプル（音の最小の時間単位）です
- `TransportClock` が、DAW から届く位置（PPQ）・BPM・拍子を、処理ブロックごとの時間軸にします
- `FxVoice` が、1 回ぶんの発音です。進み具合は `(PPQ - 開始PPQ) / 長さ` で求め、終わる位置のサンプルで止まります
- **PPQ** は、曲の中の位置を、四分音符を 1 とした数で表したものです
- DAW が止まっていて、テンポが届かないときは、`MANUAL BPM` の値を使います
- リバーブとディレイは、全体で 1 つです。`Overlap` と `Strict` を一緒に使うと、最後に鳴っている音が終わる位置で、まとめて無音になります

## 7. ソースコードの構成【作者】

```text
src/engine/   音を鳴らすエンジン。DAW や画面には依存しません
                TransportClock  DAW から届く位置（PPQ）・BPM・拍子を、処理ブロックごとの時間軸にします
                FxVoice         1 回ぶんの発音。進み具合 = (PPQ - 開始PPQ) / 長さ。終わる位置のサンプルで止まります
                SynthLayer / SampleLayer / MasterFx / FxTemplates（FX タイプとノブ）
                OfflineRenderer / WavExport
src/dsp/      ノイズ、フィルター、オシレーター、カーブ、タイムストレッチ（Rubber Band）
src/sample/   サンプルの読み込みと、コピーの管理
src/preset/   プリセットの JSON 形式、Factory プリセット、自分で保存したプリセット、パッケージ
src/ui/       画面の部品
src/          プラグインとしての外側（AudioProcessor / Editor / DAW に見せるパラメータ）
tests/        DAW の代わりをする仕組みで、エンジンとプラグインを動かす自動テスト
```

| ファイル | 内容 |
| --- | --- |
| `CMakeLists.txt` | ビルドの設定。macOS 版と Windows 版で共通です |
| `src/Storage.h` | データの保存場所を決める（`getAppDataDirectory()`）。Mac にしかないコードは、元はここ 1 か所だけです |
| `src/engine/LayerFields.cpp` | レイヤーと Master の設定項目の表 |
| `FXtend_SPEC.md` | 仕様（この資料の作成時には、中身を読めていません） |
| `docs/TEST_PLAN.md` | テストの計画と、DAW での確認手順（作者の macOS での手順） |
| `scripts/package-macos.sh` | macOS のインストーラを作るスクリプト。Windows 版には、これに当たるものがありません |
| `.github/workflows/build-windows.yml` | Windows 版のビルドの命令書【変更】 |
| `THIRD_PARTY_NOTICES.md` | 使っている部品の表記 |

### 設定項目の仕組み

- レイヤーと Master の設定項目は、`src/engine/LayerFields.cpp` にある**表 1 か所**で決めています
- DAW に見せるパラメータも、プリセットも、編集画面も、この表から作られます
- **表の id と、選択肢の並び順は、保存済みのデータと結びついています**。項目を足すときは、必ず末尾に足し、すでにあるものは変えません

### 自動テスト【作者】

自動テストは、偽のホスト（`tests/TestHost.h`）と偽の PlayHead（`tests/PluginTestSupport.h`）で、エンジンとプラグイン本体を動かします。ユーザーのフォルダには触れず、一時フォルダを使います。テストの名前の例です。

- `TimingTests`（終わる位置、テンポ変更、サンプルの位置の精度、停止中の鳴り方、ロケートとループ、連続リトリガー、バッファサイズ）
- `TailTests`（Strict と Natural、オフライン書き出しがリアルタイムと同じこと）
- `SampleTests`、`SampleFileTests`（サンプル、Stretch、欠損、保存と復元）
- `PluginTests`、`PresetTests`、`ExportTests`、`AudioRegressionTests`
- `RealtimeTests`（音を処理している最中に、メモリの確保が 0 回であること、8 ボイスを重ねたときの処理の速さ）

## 8. ビルド

### macOS（作者の手順）【作者】

Xcode と CMake 3.24 以降が必要です。JUCE 9、Rubber Band、Catch2 は、最初の `cmake` のときに、自動でダウンロードされます。

```text
cmake -B build -G Xcode
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

- ビルドが終わると、プラグインは `~/Library/Audio/Plug-Ins` の `VST3` と `Components` にコピーされます。コピーしたくないときは、`-DFXTEND_COPY_PLUGIN_AFTER_BUILD=OFF` を付けます
- スタンドアロンアプリは、`build/FXtend_artefacts/Release/Standalone/` にできます
- インストーラは、`scripts/package-macos.sh` で作ります。他の Mac で開けるようにするには、署名（`SIGN_APP`、`SIGN_PKG`）と Apple の公証（`NOTARY_PROFILE`）が必要です

### Windows（このリポジトリ）【変更】【Windows 確認】

GitHub Actions の `windows-latest` で、`.github/workflows/build-windows.yml` を動かします。

1. このリポジトリの **Actions** タブを開きます
2. 左の **Build Windows VST3** を選び、**Run workflow** を押します
3. 終わったら、実行結果のページの下の **Artifacts** から、`FXtend-VST3-Windows` をダウンロードします

命令書の中身は、次の 3 つの作業です。

```text
CXXFLAGS=/DNOMINMAX
cmake -B build -DCMAKE_BUILD_TYPE=Release -DFXTEND_COPY_PLUGIN_AFTER_BUILD=OFF
cmake --build build --config Release --target FXtend_VST3
```

- `--target FXtend_VST3` で、**プラグイン本体だけ**を作ります。テストは作りません
- **自動テスト（`ctest`）は、Windows では動いていません。** `tests/PluginTests.cpp` が、Mac の部品（CoreFoundation）を直接読み込んでいるためです
- ビルドが失敗したときは、ログの中の `error` の行を探します。一番最初の `error` が原因で、あとのものは連鎖で出ることが多いです。`warning` は、失敗の原因ではありません

## 9. このリポジトリで加えた変更【変更】

| ファイル | 変更の内容 | 理由 |
| --- | --- | --- |
| `.github/workflows/build-windows.yml` | 新しく追加 | Windows 用のビルドの命令書 |
| `src/preset/PresetPackage.cpp` | 先頭に、`ssize_t` を Windows で使えるようにする 4 行を追加（MSVC のときだけ有効） | `ssize_t` は Mac と Linux の型で、Windows にはない |
| `src/Storage.h` | Windows のときだけ、保存先を「ドキュメント」の `CHEEBOW\FXtend` にした | 設定フォルダ（AppData）より、場所が分かりやすいため |
| `NOMINMAX`（ビルドの設定） | `CXXFLAGS` に `/DNOMINMAX` を指定 | Windows の標準ヘッダーが `min` と `max` を別の式に置き換え、Rubber Band のコンパイルが失敗するため |
| `AI_CONTEXT.md`、`AGENTS.md` | 新しく追加 | AI に質問するための、非公式の資料と、答え方のルール |

## 10. 動作確認の状況

### 作者の確認（macOS）【作者】

- 作者の README と紹介ページには、Cubase、Fender Studio、Logic Pro で動作を確認した、とあります。`auval` と pluginval（strictness 10）も、VST3・AU とも通っている、とあります
- 作者のテスト計画（2026-11-12 の記録）には、pluginval 1.0.4（strictness 10）が VST3・AU とも成功したこと、自動テストを AddressSanitizer + UBSan 付きで実行して 59 件がすべて成功したこと、ThreadSanitizer 付きで 19 件が成功したことが書かれています
- 同じテスト計画の「まだ行っていない検証」には、Steinberg の VST3 `validator`、Cubase 15 / Logic Pro での実機確認、Intel Mac / Windows でのビルドが入っています。README と紹介ページの「動作確認」と、この記述の、どちらが新しいかは、資料からは分かりません

### 管理者の確認（Windows）【Windows 確認】

環境は、DAW が Fender Studio Pro 8.0.3、形式が VST3、OS が Windows（バージョンの記録なし）です。

**確認済み**: 画面の表示（表示の拡大率を変えても崩れない）、`LENGTH` で決めた小節数ぴったりで終わること、`TAIL`、`STOPPED`、6 つの FX タイプ、プリセット（試聴、読み込み、保存）、Mixer・Advanced・Master、オートメーション、サンプル（読み込み、4 つの鳴らし方、Trim・Reverse・Pitch・Mix、`extreme stretch` の警告）、Stretch、サンプルの保存と復元、`Export WAV`、プリセットパッケージ、タイミング（100 BPM、途中のテンポ変更、停止、ロケート、ループ、バッファサイズ違い、6/8 拍子）、プロジェクトの保存と開き直し、複数の立ち上げ、連続リトリガー、ドキュメントフォルダへの保存、pluginval（Strictness Level 10）、Steinberg VST3 Validator

**未確認**: アンインストールの手順、ほかの DAW、`docs/TEST_PLAN.md` のすべての項目

**動いていない**: 自動テスト（Windows では、テストをビルドしていません）

**気づいた点**: `Undo` は 1 回分しか戻れません。Stretch は、大きく伸ばすと少し濁ります。

## 11. 制限と仕様【作者】

- ノートの高さで、音程やプリセットを変えることはできません
- DAW へ WAV を直接ドラッグすることはできません。`Export WAV` を使います
- Custom 4-point カーブは、編集する画面がありません
- Windows 版には、スタンドアロンアプリ、インストーラ、コード署名がありません【変更】
- Intel Mac での動作は、作者が実機で試せていません

## 12. 用語

| 用語 | 意味 |
| --- | --- |
| VST3 | プラグインの形式の 1 つ。Windows と Mac の DAW で使えます |
| AU（Audio Unit） | Mac だけの形式。Windows にはありません |
| DAW | 音楽を作るソフト（Fender Studio Pro、Cubase、Logic Pro など） |
| インストゥルメントトラック | MIDI で鳴らす、音源プラグインを入れるトラック |
| MIDI ノート | 「この位置で音を鳴らす」という指示。ピアノロールの 1 つの四角 |
| ベロシティ | 鍵盤を押す強さ。FXtend では音量になる |
| PPQ | 曲の中の位置を、四分音符を 1 とした数で表したもの |
| サンプル | 音の最小の時間単位。または、手持ちの音の素材（WAV など）のこと |
| Stretch | 音程を変えずに、長さだけを合わせる処理（Rubber Band が担当） |
| FFT | 音を細かい周波数の成分に分けて計算する方法 |
| オートメーション | つまみの動きを時間軸に書いて、自動で動かす機能 |
| クリップ | 音が大きすぎて、割れてしまう状態 |
| ビルド | ソースコードを、実行できる形に変換して、完成品を作ること |
| MSVC | Windows の標準のコンパイラ（ソースコードを変換するソフト） |
| CMake | ビルドの手順を管理するソフト |
| GitHub Actions | GitHub のサーバーで、ビルドなどを自動で実行する機能 |
| Artifacts | GitHub Actions の完成品の置き場所 |
| pluginval | プラグインを自動で何百回も動かして、不具合がないかを調べる無料ソフト |
| Steinberg VST3 Validator | VST3 の規格を守っているかを調べる、Steinberg の検査ツール |

## 13. この資料に書かれていないこと

次のことは、確かな資料が無いので、答えられません。「資料に書かれていません」と答えるのが正しいです。

- 各ノブの、正確な効き方（ノブの名前以外）
- Factory プリセット 61 種類の、すべての名前と、中身
- Resample、Loop、One-shot の、詳しい動き
- Factory プリセットが、どのファイルに、どんな形で入っているか
- `FXtend_SPEC.md` の詳しい内容（この資料の作成時には、読めていません）
- 書き出した音の、商用などの利用条件
- Windows 版を、Windows 10 と 11 のどちらで確認したか
- Fender Studio Pro 以外の DAW での、Windows 版の動作
