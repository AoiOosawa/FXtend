# FXtend

効果音専用のプラグイン音源です。Impact、Riser、Downlifter、Sweep、Clap、Sub Drop といった、曲の展開をつなぐ音を鳴らします。

長さを「4 小節」のように決めて MIDI ノートを 1 個置けば、曲のテンポに合わせて、狙った位置でぴたりと鳴り終わります。

- **長さは小節と拍で決めます。** ノートを置いた位置から、決めた長さできっちり鳴り終わります。ノートの長さは関係ありません。
- **サンプルがなくても鳴ります。** 音はすべて内蔵のシンセ（Noise / Sub / FM / Transient / Clap）で作っていて、61 種類の Factory プリセットがすぐに使えます。
- **手持ちのサンプルも重ねられます。** WAV / AIFF を 4 つまで読み込み、Stretch、Resample、Loop、One-shot から鳴らし方を選べます。

![FXtend のメイン画面](docs/images/editor.png)

音を聞きたい方、画面をもっと見たい方は [紹介ページ](https://cheebow.github.io/FXtend/)（[English](https://cheebow.github.io/FXtend/en/)）をどうぞ。

## インストール

[最新のリリース](https://github.com/cheebow/FXtend/releases/latest) からインストーラ（`.pkg`）をダウンロードして開き、画面の案内に沿って進めてください。VST3、Audio Unit、スタンドアロンアプリの中から、入れたいものを選べます。

- macOS 12 以降
- Apple Silicon。Intel Mac でも動くように作っていますが、実機ではまだ試せていません。

### アンインストール

次のものを削除します。自分で保存したプリセットと読み込んだサンプルも消すなら、最後の 1 つも削除してください。

```text
/Library/Audio/Plug-Ins/VST3/FXtend.vst3
/Library/Audio/Plug-Ins/Components/FXtend.component
/Applications/FXtend.app
~/Library/Application Support/FXtend
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

## Windows版の動作状況

Windows版は、公式版をもとにWindows向けにビルドした非公式のVST3版です。

### 動作確認環境・検証結果

- OS：Windows
- DAW：Fender Studio Pro 8.0.3
- プラグイン形式：VST3
- pluginval：Strictness Level 10 を含む全テストに合格
- Steinberg VST3 Validator：合格

### 動作確認済みの機能

以下の機能について、Windows環境で動作を確認しています。

- **音源・再生機能**
  - 基本的な発音とタイミング制御
  - 6種類のFXタイプ
  - TAIL・STOPPED設定
- **プリセット・プロジェクト**
  - プリセットの読み込み・保存
  - プロジェクトの保存・復元
  - プリセットパッケージ（`.fxtendpack`）の書き出し・読み込み
- **サンプル編集**
  - サンプルの読み込み
  - サンプルの編集・Stretch
  - WAV書き出し
- **各種機能**
  - Mixer・Advanced・Master各ページ
  - オートメーション
  - 同じ位置で短時間に連続してノートを再トリガーする動作

### 未対応・未確認の機能

以下は、Windows版では未対応、または動作を確認できていない項目です。

- VST3以外のプラグイン形式（未対応）
- スタンドアロンアプリ（未対応）
- インストーラによる自動インストール（未対応）
- コード署名（未対応）

### 使用上の注意

- **Stretchについて**

  素材を大きく伸ばすと、音が濁る場合があります。特に長いノイズ素材などでは、伸縮率によって音質が変化するため注意してください。

## まだできないこと・知っておいてほしいこと

- **動作を確認したDAW（macOS）**：Cubase、Fender Studio、Logic Pro。`auval` と pluginval（Strictness Level 10）も、VST3・AUともに通っています。
- **ノートの高さによる音程・プリセットの変更**：ノートの高さを変えても、音程やプリセットを変更することはできません。
- **DAWへのWAVの直接ドラッグ**：書き出したWAVファイルをDAWへ直接ドラッグする機能はありません。`Export WAV` からファイルを書き出してください。
- **再生中にテンポが変わったときのStretch**：テンポが一定のあいだは、音程を保ったまま伸縮した音を鳴らします。再生中にテンポが変わると、終わる位置を合わせることを優先して再生速度を変えるため、そのあいだは音程もテンポの変化に応じてずれます。
- **OverlapとStrictを併用したときのリバーブ・ディレイ**：リバーブとディレイは全体で1つだけなので、最後に鳴っている音が終わる位置で、まとめて無音になります。
- **Custom 4-pointカーブ**：エンジンとプリセットは対応していますが、カーブを編集する画面はまだありません。

---

ここから下は、ソースコードを触る方向けです。

## ビルド

### macOS

Xcode と CMake 3.24 以降が必要です。

JUCE 9、Rubber Band、Catch2 は、最初の `cmake` の実行時に自動でダウンロードされます。

```sh
cmake -B build -G Xcode
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

ビルドが完了すると、プラグインは次の場所にコピーされます。

- VST3：`~/Library/Audio/Plug-Ins/VST3`
- Audio Unit：`~/Library/Audio/Plug-Ins/Components`

自動コピーを無効にする場合は、CMakeの実行時に次のオプションを指定してください。

```sh
-DFXTEND_COPY_PLUGIN_AFTER_BUILD=OFF
```

スタンドアロンアプリは、次の場所に生成されます。

`build/FXtend_artefacts/Release/Standalone/`

### Windows

Windows機が手元になくても、ビルドと自動テストまでならGitHub ActionsのWindowsランナーで回せます。

#### 実行方法

1. GitHubでFXtendのリポジトリを開きます。
2. リポジトリ上部の「Actions」タブを開きます。
3. 左側の一覧からWindows向けのビルドワークフローを選択します。
4. 実行履歴から確認したい実行を選択します。
5. 実行結果の画面で、各Jobを開くとビルドやテストのログを確認できます。

ワークフローが成功すれば、設定されたビルドと自動テストが正常に完了したことを確認できます。

なお、GitHub Actionsでのビルド・テストは、実際のWindows環境でDAWを使った動作確認の代わりにはなりません。

## インストーラを作る

macOS用のインストーラは、次のスクリプトで作成できます。

```sh
scripts/package-macos.sh
```

Apple SiliconとIntelの両方で動作する形でビルドし、VST3、Audio Unit、スタンドアロンアプリを含むインストーラを `build-dist/package/` に作成します。

インストール先は次のとおりです。

- `/Library/Audio/Plug-Ins/VST3`
- `/Library/Audio/Plug-Ins/Components`
- `/Applications`

ほかのMacでも開けるようにするには、コード署名とAppleの公証が必要です。次の環境変数で指定できます。指定しない場合は、署名なしのインストーラが作成されます。

| 環境変数 | 内容 |
|---|---|
| `SIGN_APP` | `Developer ID Application: 名前 (チームID)`。プラグインとアプリの署名に使用します。 |
| `SIGN_PKG` | `Developer ID Installer: 名前 (チームID)`。インストーラの署名に使用します。 |
| `NOTARY_PROFILE` | `xcrun notarytool store-credentials` で作成したプロファイル名。指定するとAppleの公証を申請し、通過後にチケットを付けます。 |

## Windows版について

Windows版は、公式版のソースコードをもとにビルドした非公式版です。

現在、Windows版ではVST3形式に対応しています。

- JUCEとRubber BandはWindowsに対応しています。
- VST3は、macOS版と同じ `CMakeLists.txt` からビルドできます。
- Audio UnitはmacOS専用の形式のため、Windowsではビルド対象になりません。
- Windows版のデータ保存先は、`src/Storage.h` でOSごとに切り替えています。

### Windows版の制限事項

- VST3以外のプラグイン形式には対応していません。
- スタンドアロンアプリには対応していません。
- Windows用の自動インストーラはありません。
- コード署名は行っていません。

### 動作確認

Windows版はFender Studio Pro 8.0.3で動作を確認しています。

また、pluginvalのStrictness Level 10を含む全テストと、Steinberg VST3 Validatorの検証に合格しています。

Stretchは、素材を大きく伸ばすと音が濁る場合があります。特に長いノイズ素材などでは、伸縮率に注意してください。

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

## このリポジトリで行ったこと

このリポジトリでは、公式版のソースコードをもとに、Windows向けの非公式ビルドを作成・公開しています。

主に次の作業を行いました。

- Windows環境でVST3プラグインをビルドできるように対応
- Windowsでのデータ保存先をOSに合わせて設定
- Fender Studio Pro 8.0.3での動作確認
- pluginval（Strictness Level 10を含む全テスト）による検証
- Steinberg VST3 Validatorによる検証
- サンプルの読み込み・編集・書き出し、プリセット、オートメーションなどの動作確認
- Windows版のZIPパッケージ作成とGitHub Releasesでの公開
- Windows版の導入方法や制限事項を含むREADMEの整備

このリポジトリは公式版の開発元とは別に管理しているもので、Windows版のビルド・検証・配布を目的としています。
