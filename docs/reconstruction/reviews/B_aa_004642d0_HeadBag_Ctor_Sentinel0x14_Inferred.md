# Review B (skeptical / adversarial): `aa_004642d0` HeadBag_Ctor_Sentinel0x14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004642d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-H) |
| **Counterpart** | `reviews/A_aa_004642d0_HeadBag_Ctor_Sentinel0x14_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall | **Falsified** — stack self; `RET 4` (`C2 04 00`) |
| 2 | Same as AssResolverCore_HeadBag / NestedHash | **Partial** — same CF/layout offsets, but sentinel is **0x14** not **0x28**; **no** AssResolver callers |
| 3 | Installs vtbl | **Falsified** — no vtbl store |
| 4 | Capacity 9 is byte count | **Falsified** — `FUN_004646e0` does `count*4` → 9 pointer slots |
| 5 | Has live static callers | **Falsified** — 0 code/data xrefs; no imm32 image match |
| 6 | Product AssResolver name sealed | **Rejected** — structural `_Inferred` only; different sentinel size |
| 7 | Decompiler void/undefined return | **Corrected** — returns self in EAX (bytes + CF twin) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI / RET 4 | **High** | Stack imbalance in port |
| Offsets +0x08..+0x24 | **High** | Corrupt bag |
| Sentinel size 0x14 | **High** | Wrong node layout vs 0x28 twins |
| Zero static callers | **High** | Missed dynamic site only |
| Product owner English | **Low** | Wrong subsystem label |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Twin 00469db0: call FUN_00423d60 (0x28) then FUN_004646e0(...,9,...)
// This 004642d0: call FUN_0043c460 (0x14) then FUN_004646e0(...,9,...)
// FUN_0043c460: push 0x14; new; *p=p; *(p+4)=p; ret  (26 B)
// Bytes end: ... 83 C4 10 C2 04 00 | CC pad
// Xrefs to 004642d0: none
```

Live decompile ≡ scaffold CF; **bytes win** on RET 4 and body size 98 B (matches twin length).

---

## 4. Surviving contract for AutoCore

```
// Port as stack placement ctor, RET 4:
HeadBag* ctor(HeadBag* self) {
  void* head = SentinelNode_New14_Circular(); // FUN_0043c460
  self->list_head = head;  // +0x08
  self->list_aux  = 0;     // +0x0c
  PtrVec_InitFill(self+0x10, /*count=*/9, &head); // FUN_004646e0
  self->flag_20 = 1;
  self->flag_24 = 1;
  return self;
}
// Do NOT alias to AssResolver bags (those use 0x28 sentinel).
// Do not invent callers; currently unreferenced in static image.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/sentinel-size distinction/0 xrefs. Product owner residual → **accept-with-gaps**.
