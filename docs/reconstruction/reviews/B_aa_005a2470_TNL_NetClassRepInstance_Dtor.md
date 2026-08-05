# Review B (skeptical / adversarial): `aa_005a2470` TNL_NetClassRepInstance_Dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2470` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W26-R) |
| **Counterpart** | `reviews/A_aa_005a2470_TNL_NetClassRepInstance_Dtor.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a constructor | **Falsified** — free + vtbl restore; no strdup/list insert; plain ret |
| 2 | This frees the ClassRep object storage | **Falsified** — only free of `+0x20` name; object free is `FUN_005a2730` bit0 path |
| 3 | This unlinks ClassList (`DAT_00d179a4`) | **Falsified** — 30 B body never touches list head |
| 4 | `__cdecl` / stack-only this | **Falsified** — `mov esi,ecx` thiscall |
| 5 | Name is at `param_1[8]` wrong vs bytes | **Falsified** — `[esi+0x20]` ≡ index 8 for dword array |
| 6 | free IAT is strdup slot | **Falsified** — free via `0x009c6524`; ctor used `_strdup` `0x009c6474` |
| 7 | Invented product name without evidence | **Falsified as risk** — pairs with sealed ctor vtbl/`+0x20`/RTTI lineage; name **High** |
| 8 | Body is every ClassRep dtor in the image | **Not claimed** — siblings exist (e.g. `FUN_005a2630`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall leaf dtor | **High** | Wrong delete path |
| free name at +0x20 | **High** | Leak or double-free wrong slot |
| vtbl restore to base | **High** | Wrong RTTI/dispatch after partial dtor |
| No ClassList unlink here | **High** | Over-porting dtor side effects |
| Product = NetClassRepInstance dtor | **High** | Naming tier only if wrong |

---

## 3. Cross-check against raw + bytes

```
name = this->className;          // +0x20
*this = NetClassRepInstance_vtbl;
free(name);
*this = base_ClassRep_vtbl;
return;
```

Clean must **not** invent ClassList removal, CRC teardown, or `operator_delete`.

---

## 4. Surviving contract for AutoCore

```c
// Port of TNL_NetClassRepInstance_Dtor
// Pair with TNL_NetClassRepInstance_Ctor — free the strdup name.
struct NetClassRepInstance {
  void* vtbl;
  // ...
  char* className; // +0x20 owned
  // ...
  NetClassRepInstance* next; // +0x34 — NOT unlinked here
};

void Dtor(NetClassRepInstance* self) {
  char* name = self->className;
  self->vtbl = NetClassRepInstance_vtbl;
  free(name);
  self->vtbl = BaseClassRep_vtbl;
}
// Scalar deleting: Dtor(p); if (flags&1) operator_delete(p);
// atexit statics: set this, call Dtor (no delete)
```

Align with in-repo `TNL.NET` ClassRep lifetime; do not leak class names.

---

## 5. Open questions

1. Whether dynamic ClassRep teardown needs a separate unlink helper.  
2. Sibling dtor catalog completeness.  
3. Live process-exit free order — deferred.

**Verdict:** **accept**
