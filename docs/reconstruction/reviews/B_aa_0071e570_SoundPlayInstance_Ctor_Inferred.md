# Review B (skeptical / adversarial): `aa_0071e570` SoundPlayInstance_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071e570` |
| **VA** | `0x0071e570` |
| **Canonical name** | `SoundPlayInstance_Ctor_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071e570_SoundPlayInstance_Ctor_Inferred.md` |
| **System** | client audio / SpecialFX play instance |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Allocates the instance | No `new`; parent `00723120` allocates | **Falsified** as allocator |
| 2 | Same as freelist slot (`0x160`) | Parent size **0x150**; stores to `+0x144` | **Falsified** same-object |
| 3 | `this` is first stack arg | Decompiler `in_EAX`; parent new→ctor | **Falsified** stack-this |
| 4 | Name at offset 0 | strcpy target **`+0x20`** | **Falsified** |
| 5 | Multi-caller utility | Single xref `00723120` | **Falsified** multi-caller |
| 6 | Pushes into list itself | Parent calls `FUN_004406e0` after | **Falsified** |
| 7 | Bounded name copy | Unbounded until NUL | **Risk** — no max in body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX this + field offsets | **Confirmed** | Wrong layout port |
| Name at +0x20 | **Confirmed** | Overwrite header |
| Leaf ctor only | **Confirmed** | False deps |
| Distinct from 0x160 queue slots | **High** | Pool mix-up |
| Param3..9 meaning | **Open** | Wrong FX attach |
| Name length bound | **Open** | buffer overrun if source huge |

---

## 3. Cross-check

```
raw ≡ live.
Parent A_aa_00723120:
  pv = operator_new(0x150)
  if pv: FUN_0071e570(...)  // EAX=pv
  FUN_004406e0()            // vector push
1 xref only.
```

### Size trap

**Do not** free/reuse these via `00480460` freelist (0x160). Different allocator family.

### ABI trap

Ghidra `__fastcall` with `param_1` = name in ECX and `this` as phantom EAX is the MSVC pattern; clean plates that drop `this` are CF-ok if documented.

---

## 4. Surviving contract for AutoCore

```
SoundPlayInstance_Ctor(this_EAX /*0x150*/, name, id16, ...):
  pack floats/ids into fixed offsets
  strcpy(this+0x20, name)
  clear +0x13C,+0x140; byte +0x144 = 0
  // does not alloc, does not push list

AutoCore must NOT:
  - call as freelist init (00480170 is different)
  - assume stack this
  - assume strncpy-bounded name without parent evidence
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Ctor field map + EAX this | **Agree Confirmed** |
| Name +0x20 | **Agree Confirmed** |
| Single caller 00723120 | **Agree Confirmed** |
| Param semantics Medium/Open | **Agree** |
| accept-with-gaps | **Agree** |
