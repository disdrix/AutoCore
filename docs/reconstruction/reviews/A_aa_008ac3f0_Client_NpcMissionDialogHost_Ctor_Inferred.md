# Review A (reconstruction fidelity): `aa_008ac3f0` Client_NpcMissionDialogHost_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac3f0` |
| **VA** | `0x008ac3f0`–`0x008ac53f` (last byte of `RET 4`) |
| **Body size** | **336 B** (`0x150`) |
| **Canonical name** | `Client_NpcMissionDialogHost_Ctor_Inferred` |
| **Ghidra symbol** | `FUN_008ac3f0` |
| **Review date** | `2026-08-05` (MEGA-107 OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_008ac3f0_Client_NpcMissionDialogHost_Ctor_Inferred.md` |
| **System** | missions-progression / client NPC mission dialog host |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `get_function_by_address`, `get_function_signature`, `get_function_callers`, `get_function_callees`, `get_function_xrefs`, `get_xrefs_to`, `get_function_call_graph`, `read_memory` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct the **NPC mission dialog host** object: base NDUI ctor, install vtable **`0x00a4a51c`**, default transform/columns/mode fields, zero mission-dialog pack (`FUN_008ab0a0`), load skin **`i_d_npc.xml`**, build response buttons (`FUN_008ac110`), virtual post-init `vtbl+0x34C` → `FUN_00791dc0`. Sole production path: `FUN_0093e7e0` `operator_new(0x748)` → this → store **`client+0x1058`**.

UI host construction only — no mission state mutation, no C2S send.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-107 append) | `docs/reconstruction/raw/aa_008ac3f0_FUN_008ac3f0.md` |
| Annotated | `docs/reconstruction/raw/aa_008ac3f0_FUN_008ac3f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_NpcMissionDialogHost_Ctor_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008ac3f0.cpp` |
| Function records | `functions/aa_008ac3f0_FUN_008ac3f0.md`, `functions/aa_008ac3f0_Client_NpcMissionDialogHost_Ctor_Inferred.md` |
| Live decompile | CF ≡ frozen raw |
| Live body bytes | full 336 B via `read_memory` |
| Vtable / string | `0x00a4a51c`, slot `+0x34C` → `0x00791dc0`, string `0x00a4b0e0` |
| Peer duals | Flush `008ab8f0`, BuildWidgets `008ad240`, BuildResponseButtons `008ac110`, ShowUI `009438f0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal (key sites)

### Prologue + base ctor

```
008ac3f0: 64 a1 00 00 00 00 6a ff 68 5d 64 9b 00 50 64 89 25 …
008ac40b: 53 57                 ; push ebx(=0), edi(=this)
008ac40f: e8 7c f4 fc ff        ; call FUN_0087b890
008ac423: c7 07 1c a5 a4 00     ; mov dword [edi], 0x00a4a51c
```

### Transform + defaults

```
0f 57 c0                    ; xorps xmm0,xmm0
f3 0f 10 0d a0 f2 a0 00     ; movss xmm1, [g_flOne]  ; 1.0f @ 0x00a0f2a0
; 12× movss into [edi+0x584..] alternating 0 / 1.0 diagonals-as-w
c7 87 fc 04 00 00 0c 00 00 00  ; [edi+0x4FC] = 0x0C
89 87 00 05 00 00              ; [edi+0x500] = 1
89 9f 48 06 00 00              ; [edi+0x648] = 0  mode
89 87 3c 06 00 00              ; [edi+0x63C] = 1
89 87 40 06 00 00              ; [edi+0x640] = 1  columns
```

### Skin + response strip + virtual

```
008ac505: e8 96 eb ff ff        ; FUN_008ab0a0
008ac50a: 68 e0 b0 a4 00        ; push "i_d_npc.xml"
008ac50f: e8 6c 64 ee ff        ; NDUIWindow_ReloadInterface @ 0x00792980
008ac514: e8 f7 fb ff ff        ; FUN_008ac110
008ac519: 8b 07 8b cf ff 90 4c 03 00 00  ; call [vtbl+0x34C]
```

### Epilogue

```
008ac53d: c2 04 00              ; RET 4
```

### Memory seals

| Addr | Result |
|---|---|
| `0x00a0f2a0` | `00 00 80 3F` = **1.0f** |
| `0x00a4b0e0` | `i_d_npc.xml\0` |
| `0x00a4a868` (`vtbl+0x34C`) | dword **`0x00791dc0`** |
| `0x00a4a958` / `95c` | BuildWidgets / Flush (peer seals) |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body envelope 336 B / `RET 4` | **pass** |
| Vtable install `0x00a4a51c` | **pass** |
| String `i_d_npc.xml` | **pass** |
| Sole caller `FUN_0093e7e0` → `client+0x1058` / size `0x748` | **pass** |
| Callee chain base → zero → XML → buttons → virtual | **pass** |
| Columns default 1 / mode 0 match peer BuildResponseButtons | **pass** |
| Product PDB class English | **gap** |
| Virtual `FUN_00791dc0` body dual | **gap** (not OWN) |
| Runtime / bit-exact | **open** |

---

## 5. ABI / control flow

| Item | Seal |
|---|---|
| Convention | Stack `this*`, **`RET 4`**, **EAX=this** |
| Working register | **EDI = this** after prologue |
| Branches | **None** (single basic block) |
| SEH | `LAB_009b645d`; states −1 / 1 / 2 / −1 |

---

## 6. Gaps

- Product / PDB name for class `0x00a4a51c`.
- Full English of base `FUN_0087b890` and virtual `FUN_00791dc0`.
- Per-field English inside `FUN_008ab0a0` zero pack (callee residual).
- Runtime host lifetime vs `+0x107c` hide sibling.

---

## 7. Verdict

**accept-with-gaps** — CF/ABI/envelope/vtable/string/caller/callee chain sealed High from live decompile + `read_memory`; product class English and nested virtual/base plates remain open. Terminal **false**.
