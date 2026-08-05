# Review A (reconstruction fidelity): `aa_008e9690` UiTargetPanel_MatchSlotAndRefresh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e9690` |
| **VA** | `0x008e9690`–`0x008e9712` (approx; ends `ret 4`) |
| **Canonical name** | `UiTargetPanel_MatchSlotAndRefresh_Inferred` (Ghidra `FUN_008e9690`) |
| **Ghidra name** | `FUN_008e9690` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_008e9690_UiTargetPanel_MatchSlotAndRefresh_Inferred.md` |
| **System** | `interaction-activation` / client select-target UI (slot panel) |
| **Verdict** | **accept-with-gaps** — 4-slot TFID match + always-call `008e9290` sealed; product slot English open |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

After select-target, refresh a **4-slot UI panel** by matching the selected world object (or its `+0xac` secondary) against slot TFID pairs, then always running the shared slot painter `FUN_008e9290`.

Sole caller: `Client_SelectTargetObject_Inferred` (`0x0093e120`):

```c
piVar2 = *(client + 0x10a0);
if (piVar2 && piVar2->vtbl[+0x3d8]())
  FUN_008e9690(piVar2);   // stack panel*
```

**ABI (bytes):**

```c
// __stdcall-ish RET 4 — one stack arg
void __stdcall UiTargetPanel_MatchSlotAndRefresh_Inferred(Panel *panel);
// EDI = selected object* (may be null) from parent register
// EBX out → slot index 0..3 or -1 into FUN_008e9290
```

CF:

1. If `EDI == 0`, skip match loop (EBX left as parent left it — see gaps).
2. Else scan **`i = 0..3`** over `slotPtr = panel + 0x5d8` (array of 4 pointers, stride 4):
   - Require `slot != 0` and `*(slot + 0x500) != 0`.
   - Match if TFID pair equal:
     - `(obj+0x160, obj+0x164) == (slot+0x508, slot+0x50c)` **OR**
     - `secondary = *(obj+0xac) != 0` and same compare on `secondary+0x160/164`.
   - On match: **break** with `EBX = i`.
3. If loop exhausts without match: **`EBX = -1`** (`or ebx, -1`).
4. **Always** `FUN_008e9290()` with `EAX = panel` (and EBX = selected slot index / −1).

`FUN_008e9290` (context only): walks same 4 slots at `+0x5d8`, marks the EBX-matched slot differently (`-1` vs `-0x51` style char), applies vfuncs — not dual-owned here.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / annotated / clean | `aa_008e9690_*`, `FUN_008e9690.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x008e9690` + `0x008e9290` + parent `0x0093e120` |
| Entry bytes | `read_memory` 128 B @ `0x008e9690` |
| Callers | sole: `FUN_0093e120` |
| Callees | `FUN_008e9290` |
| Parent dual | `A_aa_0093e120_*` (`+0x10a0` panel refresh) |

**Not performed:** dual of `008e9290`; product panel name; runtime TFID captures; Launcher.

---

## 3. Machine notes (`read_memory`)

```
85 FF                test edi, edi
53 55 56             push ebx/ebp/esi
74 65                je   after_loop          ; skip scan if no object
8B 6C 24 10          mov  ebp, [esp+0x10]   ; panel (param)
33 DB                xor  ebx, ebx
81 C5 D8 05 00 00    add  ebp, 0x5D8
; loop: load slot, test +0x500, compare +0x508/+0x50c to EDI+0x160/164
;        else EDI+0xAC secondary same compare → break
;        ebx++, ebp+=4, while ebx < 4
83 CB FF             or   ebx, -1             ; miss path only
8B 44 24 10          mov  eax, [esp+0x10]   ; panel
E8 …                 call FUN_008e9290
5E 5D 5B             pops
C2 04 00             ret 4
```

TFID-ish fields: object **`+0x160/+0x164`**, slot **`+0x508/+0x50c`**, gate **`slot+0x500`**, secondary object **`+0xac`**.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Stack arg = panel; `ret 4` | **Confirmed** | bytes |
| 4-slot array at **`panel+0x5d8`** | **Confirmed** | `add ebp,0x5d8`; `cmp ebx,4` |
| Slot live gate **`+0x500`** | **Confirmed** | cmp/jz |
| TFID pair match `+0x508/+0x50c` vs obj `+0x160/+0x164` | **Confirmed** | cmp chain |
| Secondary via **`obj+0xac`** | **Confirmed** | bytes + decompile |
| Miss → **EBX = −1** | **Confirmed** | `or ebx,-1` |
| Always call `FUN_008e9290` | **Confirmed** | after loop / skip |
| Parent panel `client+0x10a0` | **High** | sole caller dual |
| Product English (which UI) | **Open** | residual |
| EBX when `EDI==0` (skip path) | **Open** | no explicit −1 on that arm in body |
| Exact TFID layout product names | **Probable** | same id pair widths as object id fields |

---

## 5. Control flow checklist

| Stage | Match |
|---|---|
| Null EDI skip scan | **Yes** |
| 4-iteration pointer array | **Yes** |
| Dual match (self / +0xac) | **Yes** |
| Miss −1 | **Yes** |
| Unconditional paint helper | **Yes** |
| No net / physics | **Yes** |

---

## 6. Gaps

1. Product name for panel and slots.
2. OWN dual of `FUN_008e9290` (slot chrome values −1 / −0x51).
3. Seal EBX when EDI null (parent residual).
4. Runtime multi-slot selection capture.

**Verdict:** **accept-with-gaps** — match-4 + always-refresh contract sealed for select UI porting.
