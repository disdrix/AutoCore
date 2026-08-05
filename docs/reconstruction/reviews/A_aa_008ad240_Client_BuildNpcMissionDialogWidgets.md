# Review A (reconstruction fidelity): `aa_008ad240` Client_BuildNpcMissionDialogWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ad240` |
| **VA** | `0x008ad240` |
| **Canonical name** | `Client_BuildNpcMissionDialogWidgets` |
| **Review date** | `2026-07-29` (UF-011 residual — construct-only `+0x650` zero) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008ad240_Client_BuildNpcMissionDialogWidgets.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** (widget construct + **prepared-buffer zero sealed High**; full XML tree residual) |

---

## 1. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Ghidra decompile (live 2026-07-29) | `Client_BuildNpcMissionDialogWidgets` @ `0x008ad240` |
| Image (`read_memory`) | prolog + zero sequence @ `0x008ad240` / `0x008ad268` |
| Vtable DATA | `0x00a4a958` → dword `0x008ad240` (= base `0x00a4a51c` + **`0x43c`**) |
| Xrefs | **DATA only** `0x00a4a958` (virtual; no direct CALL sites) |
| Clean | `docs/reconstruction/reconstructed-exact/Client_BuildNpcMissionDialogWidgets.cpp` |
| Raw / annotated | `docs/reconstruction/raw/aa_008ad240_*` |
| Function record | `docs/reconstruction/functions/aa_008ad240_Client_BuildNpcMissionDialogWidgets.md` |
| Peer Flush (UF-011) | `reviews/A_aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` |
| Peer Prepare | `Client_NpcDialog_PrepareResponseOpcode` @ `0x008abd70` |

---

## 2. Evidence — prepared C2S buffer zero (UF-011 relation)

### 2.1 Decompiler (entry, after base init)

```c
FUN_00792600();
param_1[0x194] = 0;  // dword index
param_1[0x195] = 0;
param_1[0x196] = 0;
param_1[0x197] = 0;
param_1[0x198] = 0;
param_1[0x199] = 0;
param_1[0x19a] = 0;
param_1[0x19b] = 0;
*(undefined1 *)(param_1 + 0x160) = 0;  // byte at +0x580
// then operator_new children / MSXML loads …
```

| Mapping | Value | Confidence |
|---|---|---|
| `param_1[0x194]` byte offset | `0x194 * 4 = **0x650**` | **High** |
| Last zeroed dword | `param_1[0x19b]` → `0x19b * 4 = **0x66c**` | **High** |
| Span | **8 dwords = 0x20 bytes** | **High** |
| Match Flush send size | Flush sends size **`0x20`** from `dialog+0x650` | **High** |
| Match Prepare stamp | Prepare writes **`0x206E`** into `dialog+0x650` | **High** |
| Side clear | `param_1+0x160` → byte **`dialog+0x580` = 0** | **High** |

### 2.2 Image (`read_memory`) — construct-only zero form

At entry after `MOV EDI, ECX` / `CALL FUN_00792600`:

```text
XOR EAX, EAX
LEA ECX, [EDI+0x650]     ; 8D 8F 50 06 00 00
MOV [ECX], EAX           ; +0x650
MOV [ECX+0x04], EAX      ; +0x654
MOV [ECX+0x08], EAX      ; +0x658
MOV [ECX+0x0C], EAX      ; +0x65c
MOV [ECX+0x10], EAX      ; +0x660
MOV [ECX+0x14], EAX      ; +0x664
MOV [ECX+0x18], EAX      ; +0x668
MOV [ECX+0x1C], EAX      ; +0x66c
PUSH 0x488
MOV BYTE PTR [EDI+0x580], AL
CALL operator_new …
```

Bytes @ `0x008ad26a..`: `33 C0 8D 8F 50 06 00 00 89 01 89 41 04 … 89 41 1C 68 88 04 00 00 88 87 80 05 00 00`.

### 2.3 When `+0x650` is cleared (UF-011 answer contribution)

| Path | Clears `+0x650..+0x66c`? | Evidence |
|---|---|---|
| **This function (widget construct)** | **Yes** — full 0x20-byte prepared buffer | decompile + image |
| Flush after send (`0x008ab8f0`) | **No** | peer dual A/B |
| Cancel-close `0x9c40` → `FUN_007fca10` | **No** pre-flush clear | peer dual A/B / UF-011 |
| Prepare-on-show (`0x008abd70`) | **Writes** `0x206E` (does not clear) | Prepare dual |

**Sealed High (static):** the **only** client zero of the prepared MissionDialogResponse buffer (`dialog+0x650` size `0x20`) in the show/close/send chain is **BuildWidgets construct**. UF-011 residual “when is +0x650 zeroed?” → **here, construct-only**.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__fastcall` / `this` in ECX (`EDI=ECX`) | High | image + decomp |
| Zeros `dialog+0x650` .. `+0x66c` (8 dwords / 0x20) | **High** | image LEA +8 stores |
| That region **is** prepared C2S 0x206E buffer | **High** | peer Prepare/Flush; size match |
| Vtable slot `+0x43c` on dialog class | **High** | DATA `0x00a4a958` = `0x008ad240` |
| Only DATA xref (virtual method) | **High** | `get_function_xrefs` |
| UI-only; no mission state / packet send | High | body is child create + MSXML |
| XML `i_d_npc_2d_*` asset set | High | string refs in body |
| 4 item-slot loop + close btn `0x9c40` | High | decomp loop + close id |
| Exact reward/dialog XML product names for every child | Medium | some strings not in first visible loads |
| Safe call window vs CompleteObjective | Medium–High | plate race warning; no new counter-evidence |

---

## 4. Control flow summary

```
BuildNpcMissionDialogWidgets(dialog*):
  FUN_00792600()                         // base / list init
  zero prepared buffer dialog+0x650..+0x66c (0x20)
  zero flag byte dialog+0x580
  spawn NDUI children (new 0x488 / 0x4bc / 0x954 …)
  load i_d_npc_2d_*.xml via child vtbl+0x28 / +0xfc / +0xcc
  4× item slot cluster (btn_item / item_bg / item / itemtext)
  close button id 0x9c40 → "i_d_npc_2d_btn_close.xml"
  FUN_008ac110(); bump child counts; parent vtbl layout
  // no packet send; no +0x650 write after zero
```

Scaffold clean header + full decomp body both present; zero sequence **≡** live image.

---

## 5. Gaps (do not overclaim)

1. Full 16k child tree not re-typed field-by-field in clean scaffold.
2. Exact reward-slot → packet field mapping open (UI chrome, not wire).
3. Caller(s) of virtual `+0x43c` beyond ctor/show path not re-listed this slice (DATA-only body xrefs).
4. Runtime / bit-exact deferred.
5. MSXML race with CompleteObjective remains product caution, not newly measured.

**Verdict:** **accept-with-gaps**

**UF-011 contribution sealed High:** construct-only zero of `dialog+0x650` (prepared 0x206E buffer, 0x20 bytes). Does **not** make cancel-close safe — that path never re-enters this zero before Flush.
