# Review B (skeptical / adversarial): `aa_00508390` CVOGHBBase_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508390` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-A) |
| **Counterpart** | `reviews/A_aa_00508390_CVOGHBBase_dtor.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is the scalar deleting dtor | **Falsified** — no `operator_delete`; sibling `FUN_00508630` owns free |
| 2 | Vtbl restore only when owner present | **Falsified** — store is unconditional before `jz` |
| 3 | `FUN_005085b0(this)` with ECX=HB | **Falsified as machine ABI** — ECX becomes listMgr; stack is HB (same AttachOwner dual) |
| 4 | `__cdecl` / stack this | **Falsified** — ECX this; bare `ret` |
| 5 | Clears owner pointer / full object teardown | **Falsified** — only vtbl + optional list unlink; `+0x18` not zeroed here |
| 6 | Leaves derived vtbl in place | **Falsified** — forces base `0x009cdab0` |
| 7 | Body longer than 32 B / multi-callee | **Falsified** — single optional call + ret |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Vtbl imm / always-write | **High** | Wrong base type after derived dtor chain |
| Owner / listMgr gates | **High** | Use-after-free or double-detach |
| Callee this = listMgr | **High** | Wrong port of remove helper |
| Non-scalar (no free) | **High** | Double-free if ported as deleting dtor |
| Class name CVOGHBBase | **High** (family) | Mis-file under unrelated type |

---

## 3. Cross-check against raw + bytes

```
this->vtbl = CVOGHBBase_vtbl;   // always
if (owner && owner->listMgr)
  listMgr->Remove(this);
return;
```

Clean must **not** invent `operator_delete`, owner-nulling, or period/counter teardown. Sibling scalar `0x00508630` is a different unit.

---

## 4. Surviving contract for AutoCore

```c
// Port of CVOGHBBase_dtor (client HB complete body)
void CVOGHBBase_dtor(CVOGHBBase* self) {
  void* owner = self->pOwnerObject; // +0x18
  self->pVTable = &CVOGHBBase_vtbl; // 0x009cdab0
  if (owner) {
    void* listMgr = *(void**)((char*)owner + 0xB0);
    if (listMgr)
      ListMgr_RemoveByKey(listMgr, self); // FUN_005085b0 shape
  }
}
// Do not free(self) here. Do not clear pOwnerObject in this unit.
```

---

## 5. Open questions

1. Product mangled name.
2. Whether any caller expects vtbl already set to family before entry (derived complete dtors restore family first, then chain here which overwrites to base — correct MSVC complete order for base subobject).

**Verdict:** **accept**
