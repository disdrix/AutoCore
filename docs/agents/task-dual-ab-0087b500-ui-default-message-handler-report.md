# Dual A/B — `aa_0087b500` UI_DefaultMessageHandler

**Date:** 2026-07-29  
**Wave:** W17-F OWN-ONLY  
**Owned VA:** `0x0087b500` only  
**Tools:** Ghidra `decompile_function` / `read_memory` (no `disassemble_bytes`; no Launcher; no parent ledger edits)  
**Verdict:** **accept-with-gaps**

---

## Sealed facts

### Role

| Fact | Evidence |
|---|---|
| Default UI message fallthrough | ~109 xrefs from dialog switches |
| Swallow msg **`7..15` inclusive** → return **1** | `cmp 7` / `cmp 0x0F` + `mov al,1` |
| Else `this->vtbl+0xD8` predicate | `call [eax+0xD8]` |
| Parent at **`this+0x2B0`** | `cmp [esi+0x2B0],0` |
| Bubble `(msg, controlId)` via **`parent->vtbl+0x338`** | `push; push; call [edx+0x338]` |
| ABI **`__thiscall`**, **`ret 8`**, body **`0087b500`–`0087b54f`** | hex tail `C2 08 00` |

### Signature

```c
unsigned __thiscall UI_DefaultMessageHandler(void *pThis, int msg, unsigned controlId);
// Name INFERRED — product string not recovered
```

### Algorithm (authoritative)

```
if 7 <= msg <= 15: return 1
if !this->vtbl[+0xD8](): return 0
parent = this[+0x2B0]
if parent == 0: return 0
return parent->vtbl[+0x338](msg, controlId)
```

### Decomp defects

None material — `param_1[0xac]` ≡ `+0x2B0`.

### Call surface

| Metric | Value |
|---|---|
| Xrefs | **~109** |
| Named callers | `UI_OnAttributePointClick_Inferred`, `UI_Case_CloseBtn_9c40`, many `FUN_008*` |

### Port implication

Shared dialog default: mid-band swallow + optional parent bubble. Do not put dialog-specific logic here.

---

## Gaps

1. Product method/class name.
2. Semantic of `vtbl+0xD8`.
3. Full message enum.
4. Runtime / bit-exact verification.

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0087b500_UI_DefaultMessageHandler.md` | accept-with-gaps |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0087b500_UI_DefaultMessageHandler.md` | accept-with-gaps |

---

## Files touched / authoritative

| Role | Absolute path |
|---|---|
| Dual A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_0087b500_UI_DefaultMessageHandler.md` |
| Dual B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_0087b500_UI_DefaultMessageHandler.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_0087b500_UI_DefaultMessageHandler.md` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0087b500_FUN_0087b500.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0087b500_FUN_0087b500.annotated.md` |
| Clean | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\UI_DefaultMessageHandler.cpp` |
| This report | `C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-0087b500-ui-default-message-handler-report.md` |

Legacy scaffold (superseded for dual):  
`functions/aa_0087b500_FUN_0087b500.md`,  
`reconstructed-exact/FUN_0087b500.cpp` — prefer **UI_DefaultMessageHandler** paths.
