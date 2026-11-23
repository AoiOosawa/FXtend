# FXtend

> [!TIP]
> **FXtend について、AI に質問できます。** [AI_CONTEXT.md](docs/AI_CONTEXT.md)（使い方、インストール、ビルド、仕組みなどを、すべてまとめた資料）と [AGENTS.md](AGENTS.md)（AI の答え方のルール）の内容を、右上の⬇️ダウンロードマークから自分のPCに取り込み、それをAI に渡してから質問してください。
> 
> たとえば「`STOPPED` の使い方を教えて」のように聞くと、この資料にもとづいて答えてもらえます。渡し方は「[AI に質問するには](#ai-に質問するには)」にあります。
>
> この 2 つは、AI に渡すためのファイルです。人間向けの説明は、この README です。これらは、このリポジトリの管理者が追加した**非公式**のファイルで、作者 CHEEBOW さんのものではありません。

> [!NOTE]
> **このリポジトリは、[cheebow/FXtend](https://github.com/cheebow/FXtend) をもとにした、Windows 用の非公式ビルドです。**
>
> - 元の作者は CHEEBOW さんです。公式版（macOS 用）は [cheebow/FXtend](https://github.com/cheebow/FXtend) にあります。
> - **この README も、作者の [元の README](https://github.com/cheebow/FXtend#readme) をもとに、Windows 版の情報を加えたものです。** 元の文章はできるだけそのまま残し、足したところと書き換えたところは「[このリポジトリでの変更](#このリポジトリでの変更)」にまとめています。
> - 「動作を確認した」などの元の README の記述は、作者の macOS 版についてのものです。Windows 版の確認状況は「[Windows 版の動作状況](#windows-版の動作状況)」にあります。
> - Windows 版は、作者の公式版ではありません。Windows 版の不具合について、元の作者に問い合わせないでください。
> - ソースコードの変更点は「[Windows 版について](#windows-版について)」にあります。

効果音専用のプラグイン音源です。Impact、Riser、Downlifter、Sweep、Clap、Sub Drop といった、曲の展開をつなぐ音を鳴らします。

長さを「4 小節」のように決めて MIDI ノートを 1 個置けば、曲のテンポに合わせて、狙った位置でぴたりと鳴り終わります。

- **長さは小節と拍で決めます。** ノートを置いた位置から、決めた長さできっちり鳴り終わります。ノートの長さは関係ありません。
- **サンプルがなくても鳴ります。** 音はすべて内蔵のシンセ（Noise / Sub / FM / Transient / Clap）で作っていて、61 種類の Factory プリセットがすぐに使えます。
- **手持ちのサンプルも重ねられます。** WAV / AIFF を 4 つまで読み込み、Stretch、Resample、Loop、One-shot から鳴らし方を選べます。

![FXtend のメイン画面](docs/images/editor.png)

音を聞きたい方、画面をもっと見たい方は [紹介ページ](https://cheebow.github.io/FXtend/)（[English](https://cheebow.github.io/FXtend/en/)）をどうぞ。

## AI に質問するには

このリポジトリには、AI に渡すための資料が 2 つあります。

| ファイル | 中身 |
| --- | --- |
| [`AI_CONTEXT.md`](AI_CONTEXT.md) | FXtend の使い方、インストール、ビルド、仕組み、Windows 版の変更点、確認の状況を、すべてまとめた資料 |
| [`AGENTS.md`](AGENTS.md) | AI が、資料にもとづいて、正確に答えるためのルール |

渡し方:

1. `AI_CONTEXT.md` を開きます。右上の **Copy raw file**（ファイルの中身をコピーするボタン）を押します。
2. AI（ChatGPT、Claude、Gemini など）のチャットに、貼り付けます。
3. 同じように、`AGENTS.md` の内容も貼り付けます。
4. そのあとに、聞きたいことを書きます。たとえば、次のように聞けます。
   - 「`LENGTH` の使い方を教えて」
   - 「ノートの長さを変えても音が変わらないのは、なぜ？」
   - 「Windows で、プラグインを入れる手順を教えて」
   - 「サンプルに `Missing:` と出た。どうすればいい？」

最初に、次の文を貼ると、うまく伝わります。

```text
次に貼る 2 つの資料（AI_CONTEXT.md と AGENTS.md）を読んで、
その内容にもとづいて、FXtend の質問に答えてください。
資料に書かれていないことは、「書かれていません」と答えてください。
```

注意:

- AI は、間違えることがあります。大事なことは、資料や、作者の紹介ページで確かめてください。
- この 2 つは、非公式の資料です。作者 CHEEBOW さんが書いたものではありません。
- 資料の内容は、このリポジトリの更新に合わせて、変わります。

## インストール

### macOS（公式版）

[最新のリリース](https://github.com/cheebow/FXtend/releases/latest) からインストーラ（`.pkg`）をダウンロードして開き、画面の案内に沿って進めてください。VST3、Audio Unit、スタンドアロンアプリの中から、入れたいものを選べます。

- macOS 12 以降
- Apple Silicon。Intel Mac でも動くように作っていますが、実機ではまだ試せていません。

### Windows（非公式ビルド）

形式は **VST3 のみ**です。Audio Unit は Mac だけの形式なので、Windows にはありません。スタンドアロンアプリとインストーラも、まだありません。

1. [このリポジトリの Releases](https://github.com/GRJaoi/FXtend/releases) から、zip ファイルをダウンロードします。
2. ダウンロードした zip を右クリック → **プロパティ**を開き、下の方にある「**許可する**（ブロックの解除）」にチェックを入れて OK を押します。この表示が出ないときは、そのまま次へ進んでください。
3. zip を右クリック →「**すべて展開**」で開きます。
4. 中の **`FXtend.vst3` フォルダを、フォルダごと**、次の場所へコピーします（「管理者の許可が必要です」と出たら、続行を押します）。

   ```text
   C:\Program Files\Common Files\VST3
   ```

5. DAW を開き直して、プラグインを再スキャンします。

注意:

- `FXtend.vst3` は、**フォルダのまま**コピーしてください。中の `.vst3` ファイルだけを取り出すと、DAW が読み込めません。
- zip の中に `.lib` や `.exp` のファイルが入っていることがありますが、使いません。コピーしなくてかまいません。
- コード署名をしていないので、Windows の SmartScreen や Defender が警告を出すことがあります。上の手順 2 で、ブロックを解除してください。

### アンインストール

#### macOS

次のものを削除します。自分で保存したプリセットと読み込んだサンプルも消すなら、最後の 1 つも削除してください。

```text
/Library/Audio/Plug-Ins/VST3/FXtend.vst3
/Library/Audio/Plug-Ins/Components/FXtend.component
/Applications/FXtend.app
~/Library/Application Support/FXtend
```

#### Windows

次のものを削除します。自分で保存したプリセットと読み込んだサンプルも消すなら、最後の 1 つも削除してください。

```text
C:\Program Files\Common Files\VST3\FXtend.vst3
（ユーザーの「ドキュメント」フォルダ）\CHEEBOW\FXtend
```

## 使い方

1. インストゥルメントトラックに FXtend を立ち上げて、プリセットか FX タイプを選びます。
2. `LENGTH` で長さを決めます（たとえば 4 Bars）。それが何拍ぶんで何秒になるかは、すぐ横に表示されます。
3. 鳴らしたい位置に MIDI ノートを 1 個置きます。ノートの高さや長さは音に関係ありません。音量はベロシティで変わります。
4. `TAIL` で終わり方を選びます。`Strict` ならすぱっと無音に、`Natural` ならリバーブやディレイの余韻だけが残ります。
5. もっと作り込みたくなったら `Advanced` を開くと、レイヤーごとの設定と Master を編集できます。`Export WAV` を押せば、いまのテンポと長さのままファイルに書き出せます。

DAW を止めたままピアノロールでノートを動かすと、そのたびに試聴の音が鳴ります。これが最後まで鳴り続けないように、停止中の鳴らし方を `STOPPED` で選べます。

| `STOPPED` | DAW が止まっているあいだのノート |
|---|---|
| `Gate`（初期値） | 鍵盤を押しているあいだだけ鳴ります。離すとすぐ止まります |
| `Full` | 再生中と同じように、決めた長さを最後まで鳴らします |
| `Off` | 鳴らしません |

再生中の鳴り方は、どれを選んでも変わりません。

スタンドアロンアプリのように DAW からテンポが届かないときは、`MANUAL BPM` の値で鳴らします。そのあいだ、テンポの表示は `MANUAL` になります。

## データの保存場所

| 内容 | 場所 |
|---|---|
| 自分で保存したプリセット（`.fxpreset`、中身は JSON） | `~/Library/Application Support/FXtend/Presets` |
| 読み込んだサンプルのコピー | `~/Library/Application Support/FXtend/Samples` |

サンプルは、読み込んだときに上のフォルダへコピーされます。プロジェクトやプリセットにはそのコピーへの参照だけが保存されるので、元のファイルを動かしても、同じ Mac なら変わらず鳴ります。

別の Mac に持っていくときは、`File > Export Preset Package...` でプリセットとサンプルをひとつのファイル（`.fxtendpack`）にまとめてください。

読み込むサンプルは、利用条件を確かめたうえでお使いください。

### Windows 版（非公式ビルド）の保存場所

Windows 版は、元の作者の版（macOS 版）と違って、データを「ドキュメント」フォルダにまとめます。保存場所は、`src/Storage.h` の 1 か所で決めています。

| 内容 | 場所 |
|---|---|
| 自分で保存したプリセット（`.fxpreset`） | 「ドキュメント」フォルダの `CHEEBOW\FXtend\Presets` |
| 読み込んだサンプルのコピー | 「ドキュメント」フォルダの `CHEEBOW\FXtend\Samples` |

上の説明と同じ仕組みです。サンプルは、読み込んだときにこのフォルダへコピーされ、プロジェクトやプリセットにはそのコピーへの参照だけが保存されます。別のパソコンに持っていくときは、`File > Export Preset Package...` で `.fxtendpack` にまとめてください。

## Windows 版の動作状況

Windows 版は、次の環境で確認しています。

- DAW: Fender Studio Pro 8.0.3
- 形式: VST3
- OS: Windows

| 状態 | 項目 |
| --- | --- |
| 確認済み | 画面の表示（文字化けや欠けがない。表示の拡大率を変えても崩れない） |
| 確認済み | `LENGTH` で決めた小節数ぴったりで鳴り終わる。ノートの長さ・高さ・位置、ベロシティの扱い |
| 確認済み | `TAIL`（Strict / Natural）、`STOPPED`（Gate / Full / Off）、`Preview` |
| 確認済み | 6 つの FX タイプと、それぞれの 4 つのノブ |
| 確認済み | Presets ページ（プリセットの試聴、読み込み、保存。日本語の名前を含む） |
| 確認済み | Mixer、Advanced、Master の各ページ、オートメーション、メーターとクリップ表示 |
| 確認済み | サンプルの読み込み（ドラッグ＆ドロップ、`+ Load WAV`、日本語のファイル名、4 スロット）、4 つの鳴らし方、`Trim` / `Reverse` / `Pitch` / `Mix`、`extreme stretch` の警告 |
| 確認済み | Stretch（音程が保たれ、小節線で終わる。テンポを変えても小節線で終わる）。大きく伸ばすと、少し濁ります |
| 確認済み | サンプルの保存と復元（元のファイルを動かしても鳴る。`Missing:` の表示と、`Load...` での復帰） |
| 確認済み | `Export WAV`（24-bit / 48 kHz、32-bit float / 96 kHz、ベロシティ違い）。DAW のグリッドと書き出し位置が合う |
| 確認済み | プリセットパッケージ（`.fxtendpack`）の書き出しと読み込み |
| 確認済み | タイミング（100 BPM、途中のテンポ変更、停止、ロケート、ループ、バッファサイズ違い、6/8 拍子） |
| 確認済み | プロジェクトの保存と開き直し、複数の立ち上げ、DAW を閉じるとき、長く再生・ノート連打したとき |
| 確認済み | 同じ位置にノートを素早く置き直したとき（連続リトリガー） |
| 確認済み | 「ドキュメント」フォルダへの保存（`CHEEBOW\FXtend` の `Presets` と `Samples`） |
| 確認済み | `pluginval`（Strictness Level 10）、Steinberg VST3 Validator |
| 未確認 | アンインストールの手順 |
| 未確認 | ほかの DAW、`docs/TEST_PLAN.md` のすべての項目 |
| 動いていない | 自動テスト（Windows では、テストをビルドしていません） |

気づいた点:

- `Undo` は、1 回分しか戻れません（macOS 版でも同じ動きかは、確かめていません）。
- Stretch は、大きく伸ばすと少し濁ります。Windows では Rubber Band が内蔵の FFT で動くため、macOS 版と音が違う可能性があります。

確認が済んだ項目は、この表を更新します。

## まだできないこと・知っておいてほしいこと

- **動作を確認した DAW**: Cubase、Fender Studio、Logic Pro。`auval` と pluginval（strictness 10）も、VST3・AU とも通っています。
- **Windows** は、このリポジトリの非公式ビルド（VST3 のみ）で動きます。スタンドアロンアプリ、インストーラ、コード署名はありません。くわしくは「[Windows 版の動作状況](#windows-版の動作状況)」と「[Windows 版について](#windows-版について)」を見てください。
- **ノートの高さ**で音程やプリセットを変えることはできません。
- **DAW へ WAV を直接ドラッグ**することはできません。`Export WAV` でファイルに書き出してください。
- **再生中にテンポが変わったときの Stretch**: テンポが一定のあいだは、音程を保ったまま伸縮した音を鳴らします。途中でテンポが変わると、終わる位置を合わせることを優先して再生速度を変えるので、そのあいだは音程もテンポの変化ぶんだけずれます。
- **Overlap と Strict を一緒に使うとき**: リバーブとディレイは全体で 1 つなので、最後に鳴っている音が終わる位置でまとめて無音になります。
- **Custom 4-point カーブ**は、エンジンとプリセットは対応していますが、編集する画面がまだありません。

---

ここから下は、ソースコードを触る方向けです。

## ビルド

Xcode と CMake 3.24 以降が必要です。JUCE 9、Rubber Band、Catch2 は、最初の `cmake` のときに自動でダウンロードされます。

```sh
cmake -B build -G Xcode
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

ビルドが終わると、プラグインは `~/Library/Audio/Plug-Ins` の `VST3` と `Components` にコピーされます。コピーしたくないときは `-DFXTEND_COPY_PLUGIN_AFTER_BUILD=OFF` を付けてください。スタンドアロンアプリは `build/FXtend_artefacts/Release/Standalone/` にできます。

### Windows（非公式ビルド）

Windows 版の VST3 は、GitHub Actions の Windows 環境（`windows-latest`）でビルドしています。命令書は [`.github/workflows/build-windows.yml`](.github/workflows/build-windows.yml) です。

1. このリポジトリの **Actions** タブを開きます。
2. 左の **Build Windows VST3** を選び、**Run workflow** を押します。
3. ビルドが終わると、実行結果のページの下の **Artifacts** に、`FXtend-VST3-Windows` ができます。ここからダウンロードできます。

命令書の中身は、次の 3 つの作業です。

```text
CXXFLAGS=/DNOMINMAX
cmake -B build -DCMAKE_BUILD_TYPE=Release -DFXTEND_COPY_PLUGIN_AFTER_BUILD=OFF
cmake --build build --config Release --target FXtend_VST3
```

- `/DNOMINMAX` は、Windows の標準ヘッダーが `min` と `max` を別の式に置き換えるのを止める指定です。これがないと、Rubber Band のコンパイルが失敗します。
- `--target FXtend_VST3` で、プラグイン本体だけをビルドします。テストは、Windows ではまだビルドできません（「[Windows 版について](#windows-版について)」を見てください）。

手元の Windows でのビルドは、まだ試していません。GitHub Actions でだけ確認しています。

## インストーラを作る

```sh
scripts/package-macos.sh
```

Apple Silicon と Intel の両方で動く形でビルドし、VST3、AU、スタンドアロンアプリを入れるインストーラを `build-dist/package/` に作ります。インストール先は `/Library/Audio/Plug-Ins/VST3`、`/Library/Audio/Plug-Ins/Components`、`/Applications` です。

ほかの Mac で開けるようにするには、署名と Apple の公証が必要です。次の環境変数で指定します。指定しなければ、署名なしのインストーラができます。

| 環境変数 | 内容 |
|---|---|
| `SIGN_APP` | `Developer ID Application: 名前 (チームID)`。プラグインとアプリの署名に使います |
| `SIGN_PKG` | `Developer ID Installer: 名前 (チームID)`。インストーラの署名に使います |
| `NOTARY_PROFILE` | `xcrun notarytool store-credentials` で作ったプロファイルの名前。指定すると Apple の公証に出し、通ったらチケットを付けます |

Windows 版には、このスクリプトに当たるものがありません。

## Windows 版について

元の [cheebow/FXtend](https://github.com/cheebow/FXtend) には、Windows 版がありません。作者の README には、コードはほとんどそのまま Windows でも通る作りだが、実際にビルドして試したことはない、と書かれていました。このリポジトリは、それを GitHub Actions でビルドして、Windows で動かしてみたものです。

### ソースコードの変更点

2026 年 11 月に、元のソースコードへ次の変更を加えました。

| ファイル | 変更の内容 | 理由 |
| --- | --- | --- |
| `.github/workflows/build-windows.yml` | 新しく追加 | Windows 用のビルドの命令書。`CXXFLAGS` に `/DNOMINMAX` を指定しています |
| `src/preset/PresetPackage.cpp` | 先頭に、`ssize_t` を Windows で使えるようにする 4 行を追加（`#include <BaseTsd.h>` と `typedef SSIZE_T ssize_t;`。MSVC のときだけ有効） | `ssize_t` は Mac と Linux の型で、Windows にはない |
| `src/Storage.h` | Windows のときだけ、データの保存先を `ドキュメント\CHEEBOW\FXtend` にした（macOS の動作は変更なし） | 設定フォルダ（AppData）より、「ドキュメント」のほうが場所が分かりやすいため |
| `AI_CONTEXT.md`、`AGENTS.md` | 新しく追加 | AI に FXtend の質問に答えてもらうための、非公式の資料と、AI の答え方のルール |

### まだ対応していないもの

- **テスト**: `tests/PluginTests.cpp` が CoreFoundation を直接読み込んでいるため、Windows ではテストをビルドしていません。
- **Stretch の音と速さ**: Rubber Band は、Mac では Accelerate を使いますが、Windows では内蔵の FFT に切り替わります。大きく伸ばすと少し濁ることを確認しています。Mac 版との違いは、確かめていません。
- **スタンドアロンアプリ**: ビルドしていません。
- **インストーラ**: `scripts/package-macos.sh` に当たるものがありません。
- **署名**: コード署名の証明書がないので、ダウンロードしたときに SmartScreen の警告が出ることがあります。
- **DAW での確認**: [`docs/TEST_PLAN.md`](docs/TEST_PLAN.md) の手順は、一部しか試していません。

## ソースコードの構成

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

レイヤーと Master の設定項目は、`src/engine/LayerFields.cpp` にある表 1 か所で決めています。DAW に見せるパラメータも、プリセットも、編集画面も、この表から作られます。

**表の id と選択肢の並び順は、保存済みのデータと結びついています。項目を足すときは必ず末尾に足し、すでにあるものは変えないでください。**

仕様は [`FXtend_SPEC.md`](FXtend_SPEC.md)、テストの計画と DAW での確認手順は [`docs/TEST_PLAN.md`](docs/TEST_PLAN.md) にあります。仕様と実装が違うところは、上の「まだできないこと・知っておいてほしいこと」にまとめています。

## ロゴとアイコン

`assets/logo/` に入っています。

- **マーク**: 消えていく音と立ち上がる音が向かい合って、X の形になる絵です。
- **ロゴ**: 暗い背景用と明るい背景用があります。
- **アプリのアイコン**

元のデータは SVG で、PNG はそこから書き出したものです。ロゴの文字は [Outfit](https://github.com/Outfitio/Outfit-Fonts)（SIL Open Font License 1.1）を図形に変えてあるので、フォントが入っていない環境でも同じ形で表示されます。プラグインの画面左上のロゴも、同じ図形を描いています。

## ライセンス

Copyright © 2026 CHEEBOW

FXtend は、GNU Affero General Public License v3.0（[`LICENSE`](LICENSE)）で公開しているフリーソフトウェアです。

- [JUCE](https://juce.com) 9 を、AGPLv3 の条件で使っています。
- [Rubber Band Library](https://breakfastquay.com/rubberband/) を、GPL（v2 以降）の条件で使っています。

どちらもビルドのときにダウンロードされるもので、このリポジトリには入っていません。インストーラに入れている表記は [`THIRD_PARTY_NOTICES.md`](THIRD_PARTY_NOTICES.md) にあります。

「FXtend」という名前について、正式な商標調査はしていません。ウェブ検索で、同じ名前の音楽ソフトが見つからないことを確かめただけです。

### このリポジトリでの変更

このリポジトリは、[cheebow/FXtend](https://github.com/cheebow/FXtend) を元に、Windows でビルドできるようにしたものです。2026 年 11 月に、元のソースコードを変更しています。変更の内容は、「[Windows 版について](#windows-版について)」の表にあります。変更したソースコードも、同じ AGPL-3.0 で公開しています。

この README も、作者の [元の README](https://github.com/cheebow/FXtend#readme) をもとに、次のように変えています。

- **足したところ**: 先頭の注意書き、Windows のインストールとアンインストール、Windows 版の保存場所、「Windows 版の動作状況」の章、Windows のビルド、「インストーラを作る」の末尾の 1 文、「Windows 版について」の変更点の表、AI に質問するための案内（先頭の枠と、「AI に質問するには」の節）、この節
- **書き換えたところ**: 「まだできないこと・知っておいてほしいこと」の Windows の項目、「Windows 版について」の章
- **そのまま残したところ**: 冒頭の説明、使い方、データの保存場所（macOS の説明）、ソースコードの構成、ロゴとアイコン、ライセンス)」にあります。
>
> この 2 つは、AI に渡すためのファイルです。人間向けの説明は、この README です。これらは、このリポジトリの管理者が追加した**非公式**のファイルで、作者 CHEEBOW さんのものではありません。

> [!NOTE]
> **このリポジトリは、[cheebow/FXtend](https://github.com/cheebow/FXtend) をもとにした、Windows 用の非公式ビルドです。**
>
> - 元の作者は CHEEBOW さんです。公式版（macOS 用）は [cheebow/FXtend](https://github.com/cheebow/FXtend) にあります。
> - **この README も、作者の [元の README](https://github.com/cheebow/FXtend#readme) をもとに、Windows 版の情報を加えたものです。** 元の文章はできるだけそのまま残し、足したところと書き換えたところは「[このリポジトリでの変更](#このリポジトリでの変更)」にまとめています。
> - 「動作を確認した」などの元の README の記述は、作者の macOS 版についてのものです。Windows 版の確認状況は「[Windows 版の動作状況](#windows-版の動作状況)」にあります。
> - Windows 版は、作者の公式版ではありません。Windows 版の不具合について、元の作者に問い合わせないでください。
> - ソースコードの変更点は「[Windows 版について](#windows-版について)」にあります。

効果音専用のプラグイン音源です。Impact、Riser、Downlifter、Sweep、Clap、Sub Drop といった、曲の展開をつなぐ音を鳴らします。

長さを「4 小節」のように決めて MIDI ノートを 1 個置けば、曲のテンポに合わせて、狙った位置でぴたりと鳴り終わります。

- **長さは小節と拍で決めます。** ノートを置いた位置から、決めた長さできっちり鳴り終わります。ノートの長さは関係ありません。
- **サンプルがなくても鳴ります。** 音はすべて内蔵のシンセ（Noise / Sub / FM / Transient / Clap）で作っていて、61 種類の Factory プリセットがすぐに使えます。
- **手持ちのサンプルも重ねられます。** WAV / AIFF を 4 つまで読み込み、Stretch、Resample、Loop、One-shot から鳴らし方を選べます。

![FXtend のメイン画面](docs/images/editor.png)

音を聞きたい方、画面をもっと見たい方は [紹介ページ](https://cheebow.github.io/FXtend/)（[English](https://cheebow.github.io/FXtend/en/)）をどうぞ。

## AI に質問するには

このリポジトリには、AI に渡すための資料が 2 つあります。

| ファイル | 中身 |
| --- | --- |
| [`AI_CONTEXT.md`](AI_CONTEXT.md) | FXtend の使い方、インストール、ビルド、仕組み、Windows 版の変更点、確認の状況を、すべてまとめた資料 |
| [`AGENTS.md`](AGENTS.md) | AI が、資料にもとづいて、正確に答えるためのルール |

渡し方:

1. `AI_CONTEXT.md` を開きます。右上の **Copy raw file**（ファイルの中身をコピーするボタン）を押します。
2. AI（ChatGPT、Claude、Gemini など）のチャットに、貼り付けます。
3. 同じように、`AGENTS.md` の内容も貼り付けます。
4. そのあとに、聞きたいことを書きます。たとえば、次のように聞けます。
   - 「`LENGTH` の使い方を教えて」
   - 「ノートの長さを変えても音が変わらないのは、なぜ？」
   - 「Windows で、プラグインを入れる手順を教えて」
   - 「サンプルに `Missing:` と出た。どうすればいい？」

最初に、次の文を貼ると、うまく伝わります。

```text
次に貼る 2 つの資料（AI_CONTEXT.md と AGENTS.md）を読んで、
その内容にもとづいて、FXtend の質問に答えてください。
資料に書かれていないことは、「書かれていません」と答えてください。
```

注意:

- AI は、間違えることがあります。大事なことは、資料や、作者の紹介ページで確かめてください。
- この 2 つは、非公式の資料です。作者 CHEEBOW さんが書いたものではありません。
- 資料の内容は、このリポジトリの更新に合わせて、変わります。

## インストール

### macOS（公式版）

[最新のリリース](https://github.com/cheebow/FXtend/releases/latest) からインストーラ（`.pkg`）をダウンロードして開き、画面の案内に沿って進めてください。VST3、Audio Unit、スタンドアロンアプリの中から、入れたいものを選べます。

- macOS 12 以降
- Apple Silicon。Intel Mac でも動くように作っていますが、実機ではまだ試せていません。

### Windows（非公式ビルド）

形式は **VST3 のみ**です。Audio Unit は Mac だけの形式なので、Windows にはありません。スタンドアロンアプリとインストーラも、まだありません。

1. [このリポジトリの Releases](https://github.com/GRJaoi/FXtend/releases) から、zip ファイルをダウンロードします。
2. ダウンロードした zip を右クリック → **プロパティ**を開き、下の方にある「**許可する**（ブロックの解除）」にチェックを入れて OK を押します。この表示が出ないときは、そのまま次へ進んでください。
3. zip を右クリック →「**すべて展開**」で開きます。
4. 中の **`FXtend.vst3` フォルダを、フォルダごと**、次の場所へコピーします（「管理者の許可が必要です」と出たら、続行を押します）。

   ```text
   C:\Program Files\Common Files\VST3
   ```

5. DAW を開き直して、プラグインを再スキャンします。

注意:

- `FXtend.vst3` は、**フォルダのまま**コピーしてください。中の `.vst3` ファイルだけを取り出すと、DAW が読み込めません。
- zip の中に `.lib` や `.exp` のファイルが入っていることがありますが、使いません。コピーしなくてかまいません。
- コード署名をしていないので、Windows の SmartScreen や Defender が警告を出すことがあります。上の手順 2 で、ブロックを解除してください。

### アンインストール

#### macOS

次のものを削除します。自分で保存したプリセットと読み込んだサンプルも消すなら、最後の 1 つも削除してください。

```text
/Library/Audio/Plug-Ins/VST3/FXtend.vst3
/Library/Audio/Plug-Ins/Components/FXtend.component
/Applications/FXtend.app
~/Library/Application Support/FXtend
```

#### Windows

次のものを削除します。自分で保存したプリセットと読み込んだサンプルも消すなら、最後の 1 つも削除してください。

```text
C:\Program Files\Common Files\VST3\FXtend.vst3
（ユーザーの「ドキュメント」フォルダ）\CHEEBOW\FXtend
```

## 使い方

1. インストゥルメントトラックに FXtend を立ち上げて、プリセットか FX タイプを選びます。
2. `LENGTH` で長さを決めます（たとえば 4 Bars）。それが何拍ぶんで何秒になるかは、すぐ横に表示されます。
3. 鳴らしたい位置に MIDI ノートを 1 個置きます。ノートの高さや長さは音に関係ありません。音量はベロシティで変わります。
4. `TAIL` で終わり方を選びます。`Strict` ならすぱっと無音に、`Natural` ならリバーブやディレイの余韻だけが残ります。
5. もっと作り込みたくなったら `Advanced` を開くと、レイヤーごとの設定と Master を編集できます。`Export WAV` を押せば、いまのテンポと長さのままファイルに書き出せます。

DAW を止めたままピアノロールでノートを動かすと、そのたびに試聴の音が鳴ります。これが最後まで鳴り続けないように、停止中の鳴らし方を `STOPPED` で選べます。

| `STOPPED` | DAW が止まっているあいだのノート |
|---|---|
| `Gate`（初期値） | 鍵盤を押しているあいだだけ鳴ります。離すとすぐ止まります |
| `Full` | 再生中と同じように、決めた長さを最後まで鳴らします |
| `Off` | 鳴らしません |

再生中の鳴り方は、どれを選んでも変わりません。

スタンドアロンアプリのように DAW からテンポが届かないときは、`MANUAL BPM` の値で鳴らします。そのあいだ、テンポの表示は `MANUAL` になります。

## データの保存場所

| 内容 | 場所 |
|---|---|
| 自分で保存したプリセット（`.fxpreset`、中身は JSON） | `~/Library/Application Support/FXtend/Presets` |
| 読み込んだサンプルのコピー | `~/Library/Application Support/FXtend/Samples` |

サンプルは、読み込んだときに上のフォルダへコピーされます。プロジェクトやプリセットにはそのコピーへの参照だけが保存されるので、元のファイルを動かしても、同じ Mac なら変わらず鳴ります。

別の Mac に持っていくときは、`File > Export Preset Package...` でプリセットとサンプルをひとつのファイル（`.fxtendpack`）にまとめてください。

読み込むサンプルは、利用条件を確かめたうえでお使いください。

### Windows 版（非公式ビルド）の保存場所

Windows 版は、元の作者の版（macOS 版）と違って、データを「ドキュメント」フォルダにまとめます。保存場所は、`src/Storage.h` の 1 か所で決めています。

| 内容 | 場所 |
|---|---|
| 自分で保存したプリセット（`.fxpreset`） | 「ドキュメント」フォルダの `CHEEBOW\FXtend\Presets` |
| 読み込んだサンプルのコピー | 「ドキュメント」フォルダの `CHEEBOW\FXtend\Samples` |

上の説明と同じ仕組みです。サンプルは、読み込んだときにこのフォルダへコピーされ、プロジェクトやプリセットにはそのコピーへの参照だけが保存されます。別のパソコンに持っていくときは、`File > Export Preset Package...` で `.fxtendpack` にまとめてください。

## Windows 版の動作状況

Windows 版は、次の環境で確認しています。

- DAW: Fender Studio Pro 8.0.3
- 形式: VST3
- OS: Windows

| 状態 | 項目 |
| --- | --- |
| 確認済み | 画面の表示（文字化けや欠けがない。表示の拡大率を変えても崩れない） |
| 確認済み | `LENGTH` で決めた小節数ぴったりで鳴り終わる。ノートの長さ・高さ・位置、ベロシティの扱い |
| 確認済み | `TAIL`（Strict / Natural）、`STOPPED`（Gate / Full / Off）、`Preview` |
| 確認済み | 6 つの FX タイプと、それぞれの 4 つのノブ |
| 確認済み | Presets ページ（プリセットの試聴、読み込み、保存。日本語の名前を含む） |
| 確認済み | Mixer、Advanced、Master の各ページ、オートメーション、メーターとクリップ表示 |
| 確認済み | サンプルの読み込み（ドラッグ＆ドロップ、`+ Load WAV`、日本語のファイル名、4 スロット）、4 つの鳴らし方、`Trim` / `Reverse` / `Pitch` / `Mix`、`extreme stretch` の警告 |
| 確認済み | Stretch（音程が保たれ、小節線で終わる。テンポを変えても小節線で終わる）。大きく伸ばすと、少し濁ります |
| 確認済み | サンプルの保存と復元（元のファイルを動かしても鳴る。`Missing:` の表示と、`Load...` での復帰） |
| 確認済み | `Export WAV`（24-bit / 48 kHz、32-bit float / 96 kHz、ベロシティ違い）。DAW のグリッドと書き出し位置が合う |
| 確認済み | プリセットパッケージ（`.fxtendpack`）の書き出しと読み込み |
| 確認済み | タイミング（100 BPM、途中のテンポ変更、停止、ロケート、ループ、バッファサイズ違い、6/8 拍子） |
| 確認済み | プロジェクトの保存と開き直し、複数の立ち上げ、DAW を閉じるとき、長く再生・ノート連打したとき |
| 確認済み | 同じ位置にノートを素早く置き直したとき（連続リトリガー） |
| 確認済み | 「ドキュメント」フォルダへの保存（`CHEEBOW\FXtend` の `Presets` と `Samples`） |
| 確認済み | `pluginval`（Strictness Level 10）、Steinberg VST3 Validator |
| 未確認 | アンインストールの手順 |
| 未確認 | ほかの DAW、`docs/TEST_PLAN.md` のすべての項目 |
| 動いていない | 自動テスト（Windows では、テストをビルドしていません） |

気づいた点:

- `Undo` は、1 回分しか戻れません（macOS 版でも同じ動きかは、確かめていません）。
- Stretch は、大きく伸ばすと少し濁ります。Windows では Rubber Band が内蔵の FFT で動くため、macOS 版と音が違う可能性があります。

確認が済んだ項目は、この表を更新します。

## まだできないこと・知っておいてほしいこと

- **動作を確認した DAW**: Cubase、Fender Studio、Logic Pro。`auval` と pluginval（strictness 10）も、VST3・AU とも通っています。
- **Windows** は、このリポジトリの非公式ビルド（VST3 のみ）で動きます。スタンドアロンアプリ、インストーラ、コード署名はありません。くわしくは「[Windows 版の動作状況](#windows-版の動作状況)」と「[Windows 版について](#windows-版について)」を見てください。
- **ノートの高さ**で音程やプリセットを変えることはできません。
- **DAW へ WAV を直接ドラッグ**することはできません。`Export WAV` でファイルに書き出してください。
- **再生中にテンポが変わったときの Stretch**: テンポが一定のあいだは、音程を保ったまま伸縮した音を鳴らします。途中でテンポが変わると、終わる位置を合わせることを優先して再生速度を変えるので、そのあいだは音程もテンポの変化ぶんだけずれます。
- **Overlap と Strict を一緒に使うとき**: リバーブとディレイは全体で 1 つなので、最後に鳴っている音が終わる位置でまとめて無音になります。
- **Custom 4-point カーブ**は、エンジンとプリセットは対応していますが、編集する画面がまだありません。

---

ここから下は、ソースコードを触る方向けです。

## ビルド

Xcode と CMake 3.24 以降が必要です。JUCE 9、Rubber Band、Catch2 は、最初の `cmake` のときに自動でダウンロードされます。

```sh
cmake -B build -G Xcode
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

ビルドが終わると、プラグインは `~/Library/Audio/Plug-Ins` の `VST3` と `Components` にコピーされます。コピーしたくないときは `-DFXTEND_COPY_PLUGIN_AFTER_BUILD=OFF` を付けてください。スタンドアロンアプリは `build/FXtend_artefacts/Release/Standalone/` にできます。

### Windows（非公式ビルド）

Windows 版の VST3 は、GitHub Actions の Windows 環境（`windows-latest`）でビルドしています。命令書は [`.github/workflows/build-windows.yml`](.github/workflows/build-windows.yml) です。

1. このリポジトリの **Actions** タブを開きます。
2. 左の **Build Windows VST3** を選び、**Run workflow** を押します。
3. ビルドが終わると、実行結果のページの下の **Artifacts** に、`FXtend-VST3-Windows` ができます。ここからダウンロードできます。

命令書の中身は、次の 3 つの作業です。

```text
CXXFLAGS=/DNOMINMAX
cmake -B build -DCMAKE_BUILD_TYPE=Release -DFXTEND_COPY_PLUGIN_AFTER_BUILD=OFF
cmake --build build --config Release --target FXtend_VST3
```

- `/DNOMINMAX` は、Windows の標準ヘッダーが `min` と `max` を別の式に置き換えるのを止める指定です。これがないと、Rubber Band のコンパイルが失敗します。
- `--target FXtend_VST3` で、プラグイン本体だけをビルドします。テストは、Windows ではまだビルドできません（「[Windows 版について](#windows-版について)」を見てください）。

手元の Windows でのビルドは、まだ試していません。GitHub Actions でだけ確認しています。

## インストーラを作る

```sh
scripts/package-macos.sh
```

Apple Silicon と Intel の両方で動く形でビルドし、VST3、AU、スタンドアロンアプリを入れるインストーラを `build-dist/package/` に作ります。インストール先は `/Library/Audio/Plug-Ins/VST3`、`/Library/Audio/Plug-Ins/Components`、`/Applications` です。

ほかの Mac で開けるようにするには、署名と Apple の公証が必要です。次の環境変数で指定します。指定しなければ、署名なしのインストーラができます。

| 環境変数 | 内容 |
|---|---|
| `SIGN_APP` | `Developer ID Application: 名前 (チームID)`。プラグインとアプリの署名に使います |
| `SIGN_PKG` | `Developer ID Installer: 名前 (チームID)`。インストーラの署名に使います |
| `NOTARY_PROFILE` | `xcrun notarytool store-credentials` で作ったプロファイルの名前。指定すると Apple の公証に出し、通ったらチケットを付けます |

Windows 版には、このスクリプトに当たるものがありません。

## Windows 版について

元の [cheebow/FXtend](https://github.com/cheebow/FXtend) には、Windows 版がありません。作者の README には、コードはほとんどそのまま Windows でも通る作りだが、実際にビルドして試したことはない、と書かれていました。このリポジトリは、それを GitHub Actions でビルドして、Windows で動かしてみたものです。

### ソースコードの変更点

2026 年 11 月に、元のソースコードへ次の変更を加えました。

| ファイル | 変更の内容 | 理由 |
| --- | --- | --- |
| `.github/workflows/build-windows.yml` | 新しく追加 | Windows 用のビルドの命令書。`CXXFLAGS` に `/DNOMINMAX` を指定しています |
| `src/preset/PresetPackage.cpp` | 先頭に、`ssize_t` を Windows で使えるようにする 4 行を追加（`#include <BaseTsd.h>` と `typedef SSIZE_T ssize_t;`。MSVC のときだけ有効） | `ssize_t` は Mac と Linux の型で、Windows にはない |
| `src/Storage.h` | Windows のときだけ、データの保存先を `ドキュメント\CHEEBOW\FXtend` にした（macOS の動作は変更なし） | 設定フォルダ（AppData）より、「ドキュメント」のほうが場所が分かりやすいため |
| `AI_CONTEXT.md`、`AGENTS.md` | 新しく追加 | AI に FXtend の質問に答えてもらうための、非公式の資料と、AI の答え方のルール |

### まだ対応していないもの

- **テスト**: `tests/PluginTests.cpp` が CoreFoundation を直接読み込んでいるため、Windows ではテストをビルドしていません。
- **Stretch の音と速さ**: Rubber Band は、Mac では Accelerate を使いますが、Windows では内蔵の FFT に切り替わります。大きく伸ばすと少し濁ることを確認しています。Mac 版との違いは、確かめていません。
- **スタンドアロンアプリ**: ビルドしていません。
- **インストーラ**: `scripts/package-macos.sh` に当たるものがありません。
- **署名**: コード署名の証明書がないので、ダウンロードしたときに SmartScreen の警告が出ることがあります。
- **DAW での確認**: [`docs/TEST_PLAN.md`](docs/TEST_PLAN.md) の手順は、一部しか試していません。

## ソースコードの構成

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

レイヤーと Master の設定項目は、`src/engine/LayerFields.cpp` にある表 1 か所で決めています。DAW に見せるパラメータも、プリセットも、編集画面も、この表から作られます。

**表の id と選択肢の並び順は、保存済みのデータと結びついています。項目を足すときは必ず末尾に足し、すでにあるものは変えないでください。**

仕様は [`FXtend_SPEC.md`](FXtend_SPEC.md)、テストの計画と DAW での確認手順は [`docs/TEST_PLAN.md`](docs/TEST_PLAN.md) にあります。仕様と実装が違うところは、上の「まだできないこと・知っておいてほしいこと」にまとめています。

## ロゴとアイコン

`assets/logo/` に入っています。

- **マーク**: 消えていく音と立ち上がる音が向かい合って、X の形になる絵です。
- **ロゴ**: 暗い背景用と明るい背景用があります。
- **アプリのアイコン**

元のデータは SVG で、PNG はそこから書き出したものです。ロゴの文字は [Outfit](https://github.com/Outfitio/Outfit-Fonts)（SIL Open Font License 1.1）を図形に変えてあるので、フォントが入っていない環境でも同じ形で表示されます。プラグインの画面左上のロゴも、同じ図形を描いています。

## ライセンス

Copyright © 2026 CHEEBOW

FXtend は、GNU Affero General Public License v3.0（[`LICENSE`](LICENSE)）で公開しているフリーソフトウェアです。

- [JUCE](https://juce.com) 9 を、AGPLv3 の条件で使っています。
- [Rubber Band Library](https://breakfastquay.com/rubberband/) を、GPL（v2 以降）の条件で使っています。

どちらもビルドのときにダウンロードされるもので、このリポジトリには入っていません。インストーラに入れている表記は [`THIRD_PARTY_NOTICES.md`](THIRD_PARTY_NOTICES.md) にあります。

「FXtend」という名前について、正式な商標調査はしていません。ウェブ検索で、同じ名前の音楽ソフトが見つからないことを確かめただけです。

### このリポジトリでの変更

このリポジトリは、[cheebow/FXtend](https://github.com/cheebow/FXtend) を元に、Windows でビルドできるようにしたものです。2026 年 11 月に、元のソースコードを変更しています。変更の内容は、「[Windows 版について](#windows-版について)」の表にあります。変更したソースコードも、同じ AGPL-3.0 で公開しています。

この README も、作者の [元の README](https://github.com/cheebow/FXtend#readme) をもとに、次のように変えています。

- **足したところ**: 先頭の注意書き、Windows のインストールとアンインストール、Windows 版の保存場所、「Windows 版の動作状況」の章、Windows のビルド、「インストーラを作る」の末尾の 1 文、「Windows 版について」の変更点の表、AI に質問するための案内（先頭の枠と、「AI に質問するには」の節）、この節
- **書き換えたところ**: 「まだできないこと・知っておいてほしいこと」の Windows の項目、「Windows 版について」の章
- **そのまま残したところ**: 冒頭の説明、使い方、データの保存場所（macOS の説明）、ソースコードの構成、ロゴとアイコン、ライセンス
