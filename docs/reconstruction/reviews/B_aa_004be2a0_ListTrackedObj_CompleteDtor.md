# Review B (skeptical / adversarial): `aa_004be2a0` ListTrackedObj_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004be2a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-P) |
| **Counterpart** | `reviews/A_aa_004be2a0_ListTrackedObj_CompleteDtor.md` |
| **Scratch** | `tmp/a_004be2a0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is scalar-deleting dtor | **Falsified** — no flags arg; never `operator_delete(this)`; callers free separately |
| 2 | VOG_DEBUG_STOP plate identity | **Falsified** — xrefs are owned-object teardown sites; scaffold alias discarded |
| 3 | Ghidra noreturn truncates body | **Falsified** — 412 B reaches base vtbl store + SEH restore + `C3` |
| 4 | cdecl / stack this | **Falsified** — `MOV ESI,ECX`; thiscall complete-dtor SEH frame |
| 5 | Only frees buffers (no list/globals) | **Falsified** — DLL unlink + `DAT_00b03734/3c` + optional global self-dtor |
| 6 | `009cb5cc` is derived vtbl | **Falsified** — installed **at end** of dtor = base; derived would be set in ctor |
| 7 | `FUN_0074b580` does real work | **Falsified** — callee decompiles to empty `RET` |
| 8 | Unrelated to Elem0x28 owned@+0x24 | **Falsified** — `FUN_005b8000` calls with ECX=owned then `operator_delete` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar-deleting | **High** | Double free / leak |
| DLL + global tracking | **High** | UAF / count desync |
| Buffer + member offsets | **High** | Partial teardown |
| Base vtbl dual @+0x10/+0x20 | **High** | Wrong type after dtor |
| Product class name | **Low** | Naming only |
| Flag-path nested semantics | **Med** | Leak residual |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Elem0x28_CompleteDtor (W29-F):
if (elem->owned@0x24) {
  FUN_004be2a0(owned);   // this unit
  operator_delete(owned);
}

// Grid helpers FUN_00494530 / FUN_00497a30:
// same owned@+0x24 of 0x28-stride cells
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 stage order. Full-body hex seals epilogue after all "noreturn" deletes.

---

## 4. Surviving contract for AutoCore

```
// Port as COMPLETE dtor only:
void ListTrackedObj_CompleteDtor(Obj* self) {
  // optional flag@+0x5D0 list cleanup + FUN_004bf740(self+0x10)
  // global counts--; intrusive unlink +0/+4
  // maybe destroy global DAT_00b03730 when count hits 0
  // free buffers @+0x58C and @+0x57C; member dtors; base vtbl 009cb5cc @+0x10/+0x20
}
// Callers must operator_delete(self) separately when owning.
// Reject VOG_DEBUG_STOP scaffold plate.
// Ignore Ghidra noreturn on operator_delete.
```

---

## 5. Verdict

Adversarial pass confirms A on role/ABI/offsets/epilogue. Residual product class + nested member English → **accept-with-gaps**.
