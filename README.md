# XM8 for macOS

---
[![Downloads](https://img.shields.io/github/downloads/bubio/xm8mac/total.svg)](https://github.com/bubio/xm8mac/releases/latest)

## XM8 for macOSとは
---
XM8は、ＰＩ．さんが開発したマルチプラットフォーム（Windows/Linux/Android）に対応したPC-8801MA(PC-8801mkIISR上位互換)のエミュレータをmacOS用の改変したものです。

<p align="center">
<img width="752" src="https://user-images.githubusercontent.com/78299054/226607145-c6381e6e-acb8-4fba-88dc-0a8462298f6e.png">
</p>

このリポジトリは ＰＩ．さんから許可をいただき作成しています。

公式では配布されていないmacOS版の開発を主に行なっていきます。



公式はこちらです。

http://retropc.net/pi/xm8/index.html



## インストール方法
---

[リリース](https://github.com/bubio/xm8mac/releases)からお手持ち環境にあった実行ファイルをダウンロードしてください。

`XM8.app`を`アプリケーション`フォルダに移動するなどして実行してください。



### 動作環境

| CPU           | 最小OSバージョン    | 実行ファイル                                                 |
| ------------- | ------------------- | ------------------------------------------------------------ |
| x86_64        | Mac OS X v10.7 Lion | [x86_84版]([XM8_macOS_x86_64.zip](https://github.com/bubio/xm8mac/releases/download/1.7.0/XM8_macOS_x86_64.zip)) |
| Apple Silicon | macOS 11 Big Sur    | [Apple Silicon版](https://github.com/bubio/xm8mac/releases/download/1.7.0/XM8_macOS_AppleSilicon.zip) |

動作させるにはlibsdlが必要になります。

[Homebrew](https://brew.sh/index_ja)でインストールするのが楽だと思いますが、古いOSの場合、Homebrew自体が動作しないと思います。

その場合、[MacPorts](https://www.macports.org)経由でインストールするのが良いと思います。

## ROMファイル
---
使用できるROMファイルについては、[README-XM8.txt](Documents/README-XM8.txt)の[ROMファイル]を参照してください。

### 配置場所
ROMファイルの配置場所は、設定ファイルと同じ以下になります（一度、アプリケーションを起動するとフォルダが作成されます）。


```shell
~/Library/Application Support/retro_pc_pi/xm8
```




## 使用方法
---
[README-XM8.txt](Documents/README-XM8.txt)の[使い方]を参照してください。



## ビルド方法
---

#### ビルド環境

ビルドするには以下のインストールが必要です。

- Xcode

  使うのはコマンドラインツールだけですが、Xcodeをインストールしてしまうのが手っ取り早いと思います。

- SDL2

  SDL2のインストールが必要です。

  [Homebrew](https://brew.sh/index_ja)が楽だと思います。



#### ビルド手順

プロジェクトのルートをターミナルで開き、以下のコマンドを実行します。

```shell
cd macOS
./build_app.sh
```

これで、macOSフォルダに実行バンドルファイルが作成されているはずです。

他のプラットフォーム用のビルドについては、[README-BUILD.txt](Documents/README-BUILD.txt)を参照してください。



## 謝辞
---
ソースコードの改変を快諾してくださったＰＩ．氏にお礼申し上げます。



## おまけ

---

Linuxフォルダにdebパッケージを作成するスクリプトが入っています。

これを使う場合、BIOS ROMファイルの置き場所は以下になります。

```shell
~/.local/share/retro_pc_pi/xm8/
```

