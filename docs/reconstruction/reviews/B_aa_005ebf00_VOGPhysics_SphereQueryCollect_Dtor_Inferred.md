# Review B (skeptical / adversarial): `aa_005ebf00` VOGPhysics_SphereQueryCollect_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebf00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-038 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_005ebf00_VOGPhysics_SphereQueryCollect_Dtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Is the scalar-deleting dtor (`005ebf70`) | vtbl slot0 = `005ebf70` | **Falsified** — this VA is complete dtor; only caller is `005ebf70`, which optionally frees after |
| 2 | Is the base query dtor (`006343d0`) | tail JMP target | **Falsified** — body first tears down **+0xC0** triad; then chains to base |
| 3 | Is the sphere collect **ctor** (`005ebec0`) | same vtbl write | **Falsified** — ctor empty-inits triad; this walks/frees it |
| 4 | Is sibling-collect dtor (vtbl `009dce20`) | family merge | **Falsified** — installs `009dce90` only (sphere derived) |
| 5 | stdcall / bare RET / no this | decompiler `__fastcall` / `undefined` return | **Falsified** — `MOV EDI,ECX`; ends `JMP` with ECX restored |
| 6 | Frees the outer 0xD0 object | dtor free guess | **Falsified** — free targets buffer begin with tag **0x12**; whole free is peer `005ebf70` tag **0x2C** |
| 7 | Element stride is 4 (pointer vector) | base dtor triad pattern | **Falsified** — `ESI*8` addressing + free size `cap*8` |
| 8 | Free size is raw signed capacity without mask | decompiler `param_1[0x32]*8` | **Falsified** — asm `AND 0x7fffffff` before ×8 (for `cap>=0` path equivalent) |
| 9 | Empty triad always frees | sentinel guess | **Falsified** — `TEST/JS` skips free when capacity signed-negative (`0x80000000`) |
| 10 | Product class name sealed (no `_Inferred`) | Wishful RTTI | **Fails (open)** — DATA xrefs = ctor + this dtor only; no `.?AV…` |
| 11 | Runtime Confirmed | Wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |
| 12 | Multiple direct callers | xref noise | **Falsified** — sole UNCONDITIONAL_CALL from `FUN_005ebf70` @ `005ebf73` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall no-args / tail JMP base | **High** | Leak or double-free on destroy path |
| +0xC0 triad walk/free / stride 8 | **High** | Collect buffer leak or UAF |
| Pair with sphere ctor vtbl `009dce90` | **High** | Wrong type lifecycle |
| Distinct from scalar / base / sibling | **High** | Merge wrong dtor |
| Product class English | **Low–Med** | Doc only (`_Inferred`) |
| Element type / release slot | **Low–Med** | Port naming only |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
// sealed CF (assembly-corrected)
self = ECX
count = self[+0xC4]
*self = &PTR_FUN_009dce90
for i = count-1; i >= 0; i--:
  entry_obj = *(obj**)(self[+0xC0] + i*8)
  vcall(entry_obj, slot +0x14)            // thiscall
self[+0xC4] = 0
if (int)self[+0xC8] >= 0:
  free(self[+0xC0], (cap & 0x7fffffff)*8, tag 0x12)
JMP FUN_006343d0(self)                    // thiscall base dtor
```

Sibling contrast (evidence only; not OWN dual):

* `FUN_005ebec0` — dualed sphere collect **ctor**; same vtbl + empty triad.
* `FUN_005ebf70` — **scalar-deleting** dtor; calls this then optional free tag 0x2C.
* `FUN_006343d0` — **base** dtor (internal triads / tag 0x12 at base offsets).
* `FUN_005eb210` — dualed base **ctor** (partition parent).
* `FUN_005eb790` — sibling collect ctor (vtbl `009dce20`).

Bytes seal (`read_memory` 104 B):

```text
56 57 8B F9 8B B7 C4 00 00 00 83 EE 01 C7 07 90 CE 9D 00 …
… 8B 0C F0 … FF 52 14 …                         ; element vcall +0x14
… C7 87 C4 00 00 00 00 00 00 00 …               ; count = 0
… 25 FF FF FF 7F 03 C0 03 C0 6A 12 03 C0 …     ; mask; ×8; tag 0x12
… 8B CF 5F 5E E9 68 84 04 00 CC…               ; MOV ECX,EDI; JMP 006343d0; pad
```

---

## 4. Surviving contract for AutoCore

```
VOGPhysics_SphereQueryCollect_Dtor_Inferred(self):
  self.vtbl = PTR_FUN_009dce90
  for each collect entry reverse:
    Release(entry.obj)                 // vtbl[+0x14]
  collect.count = 0
  if collect.capacity >= 0:
    AllocatorFree(collect.begin, capacity*8, tag=0x12)
  BaseQueryDtor(self)                  // FUN_006343d0
  // thiscall, no stack args; do not free outer 0xD0 here
```

**Port tests:**

* After dtor of empty collect (cap `0x80000000`): no buffer free call; base dtor still runs.
* After dtor with N hits: N element releases + one buffer free size N_cap*8 tag 0x12.
* Scalar delete path: complete dtor then free object size 0xD0 tag 0x2C.
* Do **not** implement as base dtor, sibling-collect dtor, or outer free.
* Preserve thiscall on self and on per-element release (decompiler drops this).

**Verdict:** **accept-with-gaps** — adversarial scalar-merge / base-merge / ctor-merge / sibling-merge / wrong-ABI / outer-free / stride-4 claims **all falsified**. Product English, element type, residual base/scalar duals, and runtime remain open (terminal false).
