# Review A (reconstruction fidelity): `aa_008ab0a0` Client_NpcMissionDialog_InitRuntimeFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab0a0` |
| **VA** | `0x008ab0a0` |
| **Canonical name** | `Client_NpcMissionDialog_InitRuntimeFields_Inferred` (Ghidra `FUN_008ab0a0`) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_008ab0a0_Client_NpcMissionDialog_InitRuntimeFields_Inferred.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Mid-ctor runtime field init / sentinel pack** on the NPC mission-dialog host:

1. Zero widget/chrome/list pointer fields and chrome mode `+0x510`.
2. Seed **4×** reward/chrome id banks with `−1` TFID pairs + zero related slots.
3. Seed **8×** response TFID pairs (`+0x518`) with `−1` and null widgets (`+0x708`).
4. Install three default float4s (`+0x584`, `+0x594`, `+0x5a4`) from image constants.
5. Clear turn-in flag `+0x64c`.

Sole CALL: host ctor `Client_NpcMissionDialogHost_Ctor_Inferred` immediately before `ReloadInterface("i_d_npc.xml")`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra | `decompile_function` + `analyze_function_complete` @ `0x008ab0a0` |
| Body bounds | `get_function_by_address` → `008ab0a0`–`008ab33d` |
| Disasm | `disassemble_function` (ABI/offsets; **not** `disassemble_bytes`) |
| Callers / xrefs | `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` |
| Caller framing | `get_assembly_context` @ `008ac505` + parent decompile |
| Constants | `read_memory` @ `00a0f2a0`, `00a0f71c`, `00aaa7e4`, `00aaa7e8`, `00a4a8c8` |
| Raw | `docs/reconstruction/raw/aa_008ab0a0_FUN_008ab0a0.md` (+ R11-035 append) |
| Annotated | `docs/reconstruction/raw/aa_008ab0a0_FUN_008ab0a0.annotated.md` |
| Clean | `reconstructed-exact/Client_NpcMissionDialog_InitRuntimeFields_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_008ab0a0.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 670 B / `0x29E` | **High** | bounds + RET `C3` + `CC CC` pad before `008ab340` |
| ECX = dialog host this | **High** | all stores `[ECX+disp]`; caller `MOV ECX,EDI` |
| No stack args / plain RET | **High** | ends `5E 83 C4 10 C3` |
| Leaf (no callees) | **High** | analyze + disasm: no CALL |
| Sole CALL site in ctor | **High** | xrefs: 1 UNCONDITIONAL_CALL + 1 DATA |
| Response bank `+0x518/+0x708` | **High** | matches dualed clear `008aa560` |
| Chrome grid `+0x698..+0x6d4` zeros | **High** | 4-slot pattern; used by ApplyPanelMode |
| Float constants 0.6 / 0.157 / 0.549 / 1.0 | **High** | `read_memory` |
| Turn-in `+0x64c` clear | **High** | `MOV [ECX+0x64c],AL` with AL=0 |
| Product method English | **Open** | `_Inferred`; vtbl+0x3AC demangle open |
| Float4 semantic role | **Tentative** | color vs layout open |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Live | Clean |
|---|---|---|---|
| Zero pointer pack | Yes | Yes | Yes |
| 4× −1 / 0 banks | Yes | Yes | Yes |
| 8× response banks | Yes | Yes | Yes |
| Three float4 writes | Yes | Yes | Yes |
| `+0x64c = 0` | Yes | Yes | Yes |
| Invented branches | — | — | **None** (straight-line leaf) |

**Result:** Clean CF ≡ raw ≡ live Ghidra. ABI corrected to ECX thiscall (decompiler `int param_1` / empty prototype).

---

## 5. Assembly seals (no disassemble_bytes)

| Pattern | Meaning |
|---|---|
| `83 EC 10 56 33 C0` | frame + ESI; EAX=0 |
| `89 81 …` | store 0 → `[ECX+disp]` |
| `0F 57 C0` / `83 CA FF` | XMM0=0; EDX=−1 |
| `89 91 …` | store −1 → `[ECX+disp]` |
| `F3 0F 10 …` loads | `DAT_00a0f71c` / `DAT_00aaa7e8` / `g_flOne` / `DAT_00aaa7e4` |
| `88 81 4C 06 00 00` | `[ECX+0x64c]=0` |
| `5E 83 C4 10 C3` | restore + plain RET |

### Caller seal

```
008ac4bb  MOV ECX, EDI
… [EDI+…] stores only …
008ac505  CALL 0x008ab0a0
008ac50a  PUSH "i_d_npc.xml"
008ac50f  CALL NDUIWindow_ReloadInterface
008ac514  CALL UI_MissionDialog_BuildResponseButtons_Inferred
```

---

## 6. Gaps

1. Product/PDB name for vtbl+0x3AC.
2. Product meaning of three float4 banks.
3. Whether any virtual dispatch path hits this slot outside ctor.
4. Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — ECX ABI, 670 B body, leaf field pack, bank offsets, float constants, and sole ctor CALL sealed; product English open. No runtime Confirmed.
