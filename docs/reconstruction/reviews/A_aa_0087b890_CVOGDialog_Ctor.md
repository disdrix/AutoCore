# Review A (reconstruction fidelity): `aa_0087b890` CVOGDialog_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0087b890` |
| **VA** | `0x0087b890`–`0x0087b905` (last byte of `RET 8`) |
| **Body size** | **118 B** (`0x76`) |
| **Canonical name** | `CVOGDialog_Ctor` |
| **Ghidra symbol** | `FUN_0087b890` |
| **Review date** | `2026-08-05` (R11-030 OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0087b890_CVOGDialog_Ctor.md` |
| **System** | missions-progression (partition parent `0x008ac3f0`); shared CVOGDialog base |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `get_function_by_address`, `get_function_signature`, `get_function_callers`, `get_function_xrefs`, `read_memory` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct a **CVOGDialog** object:

1. SEH frame (`LAB_009b531d`).
2. Base ctor `FUN_00792d20` (CNDUIDialog peer — intermediate vtbl `0x00a98f44`).
3. Zero dword pack at `+0x4FC / +0x500 / +0x504 / +0x508` and bytes `+0xBF`, `+0x490`.
4. Install primary vtbl **`0x00a58c6c`** (RTTI **`.?AVCVOGDialog@@`**).
5. Store second ctor arg at **`+0x2A4`**.
6. Return `this` in EAX; **`RET 8`**.

UI base construction only — no mission state mutation, no network, no XML load (those belong to subclasses).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R11-030 append) | `docs/reconstruction/raw/aa_0087b890_FUN_0087b890.md` |
| Annotated | `docs/reconstruction/raw/aa_0087b890_FUN_0087b890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGDialog_Ctor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0087b890.cpp` |
| Function records | `functions/aa_0087b890_FUN_0087b890.md`, `functions/aa_0087b890_CVOGDialog_Ctor.md` |
| Live decompile | CF ≡ frozen raw |
| Live body bytes | full 118 B via `read_memory` |
| Vtable / RTTI | `0x00a58c6c`, COL `0x00ab4984`, type_info `0x00af8e50` → `.?AVCVOGDialog@@` |
| Parent evidence | `Client_NpcMissionDialogHost_Ctor_Inferred` calls `(this, 0)` then overwrites vtbl |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, parent ledger edits.

---

## 3. Byte seal (key sites)

### Prologue + base

```
0087b890: 64 a1 00 00 00 00 6a ff 68 1d 53 9b 00 50 64 89 25 …
0087b8a5: 56 8b 74 24 14     ; ESI = this (stack)
0087b8a9: 56 e8 70 74 f1 ff  ; push this; call FUN_00792d20
```

### Field zeros + vtbl + arg

```
33 c0
89 86 04 05 00 00   ; [esi+0x504]=0
89 86 08 05 00 00   ; [esi+0x508]=0
89 86 fc 04 00 00   ; [esi+0x4FC]=0
89 86 00 05 00 00   ; [esi+0x500]=0
88 86 bf 00 00 00   ; [esi+0xBF]=0
88 86 90 04 00 00   ; [esi+0x490]=0
8b 44 24 18         ; EAX = param_2
c7 06 6c 8c a5 00   ; *esi = 0x00a58c6c
89 86 a4 02 00 00   ; [esi+0x2A4] = param_2
```

### Epilogue

```
0087b900: 83 c4 0c     ; ADD ESP, 0xC
0087b903: c2 08 00     ; RET 8
0087b906: cc …         ; pad
```

### Memory seals

| Addr | Result |
|---|---|
| Body end | `RET 8` @ `0x0087b903`; size **118 B** |
| `0x00a58c68` | COL ptr `0x00ab4984` |
| `0x00af8e50` | `.?AVCVOGDialog@@\0` |
| `0x00a58c6c` | vtbl slot0 dword `0x004130d0` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body envelope 118 B / `RET 8` | **pass** |
| Vtable install `0x00a58c6c` | **pass** |
| RTTI class `CVOGDialog` | **pass** |
| Sole callee `FUN_00792d20` | **pass** |
| Multi-caller dialog base (78 xrefs) | **pass** |
| Parent mission host uses `(this,0)` then subclass vtbl | **pass** (evidence) |
| Product English for `param_2` / mode dwords | **gap** |
| Full object size (varies by subclass) | **gap** |
| Runtime / bit-exact | **open** |

---

## 5. ABI / control flow

| Item | Seal |
|---|---|
| Convention | Stack `this*`, `param_2`; **`RET 8`**; **EAX=this** |
| Working register | **ESI = this** after load from `[esp+0x14]` |
| Branches | **None** (single basic block; CC 1) |
| SEH | `LAB_009b531d`; states −1 / 0 / −1 |

---

## 6. Gaps

- Product English for ctor arg `param_2` and field `+0x2A4`.
- Official names for zeroed mode dwords at `+0x4FC..+0x508`.
- CVOGDialog complete layout / base size (subclasses differ: `0x748`, `0x5B0`, …).
- Runtime lifetime / differential.
- Base `FUN_00792d20` naming tension (CNDUIDialog RTTI vs prior `NDUIContainerPanel_Ctor_Inferred` plate) — **not owned**.

---

## 7. Verdict

**accept-with-gaps** — CF/ABI/envelope/RTTI-vtbl/callee/caller fan-out sealed High from live decompile + `read_memory`; product field English and runtime remain open. Terminal **false**.
