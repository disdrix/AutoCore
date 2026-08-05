# Review A (reconstruction fidelity): `aa_0046a260` StdUninitFillN_Elem28_CountEcx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046a260` |
| **VA** | `0x0046a260`–`0x0046a281` (**34 B** / `0x22`) |
| **Canonical name** | `StdUninitFillN_Elem28_CountEcx_Inferred` |
| **Ghidra name** | `FUN_0046a260` |
| **Review date** | `2026-07-29` (W36-M dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-M) |
| **Counterpart** | `reviews/B_aa_0046a260_StdUninitFillN_Elem28_CountEcx_Inferred.md` |
| **System** | stl-helpers / POD uninit fill-n (elem 0x1c) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 34 B) + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Leaf uninit fill-n for POD T size **0x1c**:

1. If `count == 0` (ECX, unsigned `JBE`), return.
2. Else loop count times: if dest (EAX) non-null, `REP MOVSD` 7 dwords from template (EBX); always `dest += 0x1c`; count--.
3. Bare `RET`.

Used by ValueEdx insert-n (`FUN_00469f50`) and `FUN_00469c80` (single-element push).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-M append) | `docs/reconstruction/raw/aa_0046a260_FUN_0046a260.md` |
| Annotated | `docs/reconstruction/raw/aa_0046a260_FUN_0046a260.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_Elem28_CountEcx_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0046a260.cpp` |
| Function records | `functions/aa_0046a260_FUN_0046a260.md`, `functions/aa_0046a260_StdUninitFillN_Elem28_CountEcx_Inferred.md` |
| Live | decompile ≡ bytes; 3 call sites / 2 parents |
| Pair | `AnmTrackMaster_Unserialize_Inferred` (`0x00459750`) — same dual wave |

---

## 3. Signature (sealed — bytes win)

```c
// Register ABI; bare RET; leaf
// Decompiler: void __fastcall (int count ECX) + phantoms in_EAX / unaff_EBX
void StdUninitFillN_Elem28_CountEcx_Inferred(
    uint32_t count /*ECX*/,
    Elem28* dest /*EAX*/,
    const Elem28* tmpl /*EBX*/);
```

| Slot | Source | Conf |
|---|---|---|
| count | ECX → EDX working | **High** |
| dest* | EAX | **High** |
| template* | EBX | **High** |
| RET | bare `C3` | **High** |
| stack formals | **none** | **High** |
| stride | `ADD EAX,0x1C` + `REP MOVSD` ×7 | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if count == 0: return
loop:
  if dest != null: copy 7 dwords from tmpl (REP MOVSD)
  dest += 1 element (0x1c)
  count--
  if count != 0: goto loop
return
```

| Stage | Match | Conf |
|---|---|---|
| Zero-count early out | **Yes** (`TEST ECX` / `JBE`) | **High** |
| Null-safe store | **Yes** (`TEST EAX` / `JZ`) | **High** |
| Always advance dest | **Yes** | **High** |
| Template not advanced | **Yes** (EBX held; ESI reloaded) | **High** |
| Leaf | **Yes** (0 callees) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 34 B hex:

```
85c9761d568bd15785c0740bb9070000008bf38bf8f3a583c01c83ea0175e95f5ec3
```

Entry: `TEST ECX,ECX; JBE done`.  
Epilogue: `POP EDI; POP ESI; RET`. Pad `CC` then next @ `0x0046a290`.

---

## 6. Verdict

Full leaf contract sealed from bytes + decompile + parents → **accept**.
