# Review B (skeptical / adversarial): `aa_004962b0` EquipGfxHost_ClearListIfFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004962b0` |
| **VA** | `0x004962b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B create) |
| **Counterpart** | `reviews/A_aa_004962b0_EquipGfxHost_ClearListIfFlag_Inferred.md` |
| **Scratch** | `reviews/a_004962b0.md` |
| **System** | `inventory-transfer` / client gfx host |
| **Verdict** | **accept-with-gaps** — CF/ABI/gate/`+0xA8` adjust sealed; reject incomplete decompile as authority |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompile `FUN_004367f0(0,0)` is complete CF | Check bytes for hidden ops | **Falsified as complete** — `add ecx,0xA8` present; this is **not** a null-this call |
| 2 | Body rebuilds meshes / attaches hardpoints | Scan for equip helpers | **Falsified** — only optional vector resize callee |
| 3 | Always clears the list | Flag always true? | **Falsified** — `je` no-op when `host+0x53==0` |
| 4 | `__stdcall` / stack args on **this** unit | `ret N`? | **Falsified** — plain `c3`; stack args belong to **callee** |
| 5 | Callee is “FX unload by name” with two zero handles | Identity of `004367f0` | **Falsified** — dword-vector resize (`begin/end`, `>>2`, `ret 8`) |
| 6 | `push 0; push 0` means two independent resource IDs | Compare to callee ABI | **Falsified** — count=0 + fill slot for grow path; shrink ignores fill |
| 7 | ECX ignored / global refresh | Sites pass host | **Falsified** — all sites load host into ECX; body uses ECX |
| 8 | Only called from PostCreateFromPacket | Xref dump | **Falsified** — **13** sites incl. equip wrapper, destroy, client UI |
| 9 | Same as parent `0x0092f120` | Size/role | **Falsified** — parent is dual-null gate + **tail jmp**; this is the worker |
| 10 | Product name sealed | RTTI/string on body | **Sustained risk** — keep `_Inferred` |
| 11 | Vector holds “equip items” specifically | Element type | **Open** — stride-4 only; do not invent item* |
| 12 | Runtime / bit-exact verified | Policy | **Open** — static seal only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Flag gate `+0x53` polarity | **High** | Port always-clears or never-clears |
| `this` adjust `+0xA8` before call | **High** | Clear wrong object / null deref myth |
| Callee = vector resize-to-0 | **High** | Invented asset API |
| Own ABI: ECX host, 0 stack, `ret` | **High** | Stack imbalance in port |
| No equip mutation in body | **High** | Double-count equip side effects |
| Element English / flag English | **Low–Open** | Misnamed docs |
| “Refresh” == full gfx rebuild | **Rejected** | Overclaim vs clear-list |

---

## 3. Cross-check: raw decompile vs bytes

Frozen raw / live decompile:

```c
void __fastcall FUN_004962b0(int param_1)
{
  if (*(char *)(param_1 + 0x53) != '\0') {
    FUN_004367f0(0,0);   // incomplete
  }
}
```

Machine-faithful:

```c
void __fastcall EquipGfxHost_ClearListIfFlag_Inferred(void *host)
{
  if (*(char *)((char *)host + 0x53) != 0)
    FUN_004367f0((char *)host + 0xA8, 0, 0);  // resize vector to 0
}
```

**Adversarial rule:** any port or doc that quotes only the Ghidra text without `+0xA8` is **wrong**.

---

## 4. Surviving contract for AutoCore

```
// ECX = gfx host (typically *(vehicleOrClientObj + 0xE898))
EquipGfxHost_ClearListIfFlag_Inferred(host):
  if host[0x53] == 0: return
  VectorDword_Resize(host + 0xA8, count=0)   // FUN_004367f0; clears if non-empty
```

**Port rules:**

* Do **not** treat as inventory equip/unequip.
* Do **not** omit the `+0xA8` this-adjust.
* Do **not** call with null host (callers null-check `+0xE898` first; body does not).
* Safe no-op when flag clear **or** vector already empty.
* Parent `Client_MaybeRefreshEquipGfxHost` is optional **entry**; this is the **shared leaf**.

---

## 5. Parent dual residual (corrective note only)

`A/B_aa_0092f120_*` summarize callee as `if flag then FUN_004367f0(0,0)`. That is **under-specified** (missing `host+0xA8` this). Full callee seal lives **here** (OWN VA). Parent duals were not rewritten this pass (OWN-ONLY).

---

## 6. Open questions

1. Who writes `host+0x53` (set/clear producers)?
2. What pointers/ids live in the `+0xA8` vector?
3. PDB / retail symbol for this leaf and host class.
4. Runtime confirm clear happens after equip notify.

**Verdict:** **accept-with-gaps** — attacks on “full refresh,” incomplete decompile authority, dual-null-less body, and equip mutation **closed**; product naming + element semantics + runtime remain open.
