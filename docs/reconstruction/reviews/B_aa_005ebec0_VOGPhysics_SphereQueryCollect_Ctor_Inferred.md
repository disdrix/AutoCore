# Review B (skeptical / adversarial): `aa_005ebec0` VOGPhysics_SphereQueryCollect_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-070 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_005ebec0_VOGPhysics_SphereQueryCollect_Ctor_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity is `Named_CalleeOf_Named_VOG_DEBUG_STOP_*` | Scaffold alias from parent assert path | **Falsified** — body never references VOG_DEBUG_STOP; pure ctor |
| 2 | Is the sphere-shape object (`FUN_006c7fa0`) | Partition “sphere” hint merge | **Falsified** — shape is separate 0x10 alloc/tag 0x22; this is 0xD0/tag 0x2C |
| 3 | Is the full GetObjectsInArea collect loop | Parent `004ea350` skim | **Falsified** — 49 B straight-line; collect is `FUN_00560c90` + parent walk |
| 4 | Is AABB query ctor (mode-1 / default) | Same parent multi-mode | **Falsified** — only mode-2 / sphere branch call sites; AABB uses `FUN_00581220` / 0x90 size |
| 5 | stdcall / bare RET / no this | Decompiler void noise on siblings | **Falsified** — `MOV ESI,ECX`; `RET 4`; call sites set ECX=alloc |
| 6 | Does not return this / returns void | classification “wrapper” + undefined return | **Falsified** — `MOV EAX,ESI` before RET |
| 7 | Collect triad is refcount / physics handle | Offset guess | **Falsified** — dtor walks `[+0xC0]` by count `[+0xC4]` and frees with capacity `[+0xC8]` |
| 8 | Product class name sealed (no `_Inferred`) | Wishful RTTI | **Fails (open)** — vtbl DATA xrefs are ctor/dtor only; no `.?AV…` on vtbl |
| 9 | Runtime Confirmed | Wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |
| 10 | Base ctor is this VA | Single-function merge | **Falsified** — base is `FUN_005eb210` @ `0x005eb210` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 4 / ECX=self | **High** | Corrupt every construct site |
| Derived vtbl + collect triad | **High** | Wrong object init → collect crash |
| Sphere-only role vs AABB | **High** | Wrong alloc size / mode branch |
| Distinct from shape `006c7fa0` | **High** | Merge shape and query types |
| Product class English | **Low–Med** | Doc only (`_Inferred`) |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
// sealed CF
self = ECX
params = [ESP+4]
FUN_005eb210(params)          // thiscall base; ECX=self
*self = &PTR_FUN_009dce90
self[0x30] = 0                // +0xC0
self[0x31] = 0                // +0xC4
self[0x32] = 0x80000000       // +0xC8
return self                   // EAX; RET 4
```

Sibling contrast (evidence only; not OWN dual):

* `FUN_006c7fa0` — sphere **shape** setup (MEGA-071); alloc 0x10 / tag 0x22.
* `FUN_00581220` — AABB-path query ctor (0x90) used when `param_5==1` / non-sphere.
* `FUN_005ebf00` — dtor releases collect triad; confirms buffer semantics.
* `FUN_004ea350` — parent `CVOGPhysicsUtils::GetObjectsInArea` (string `…::aabb` @ `0x009ccbe8`); sphere branch uses this ctor.

Bytes seal (`read_memory`):

```text
8B 44 24 04 56 50 8B F1 E8 43 F3 FF FF C7 06 90 CE 9D 00
33 C0 89 86 C0 00 00 00 89 86 C4 00 00 00
C7 86 C8 00 00 00 00 00 00 80 8B C6 5E C2 04 00 CC...
MOV EAX,[ESP+4]; PUSH ESI; PUSH EAX; MOV ESI,ECX; CALL base;
MOV [ESI],vtbl; zero +0xC0/+0xC4; MOV +0xC8,0x80000000; MOV EAX,ESI; POP ESI; RET 4
```

---

## 4. Surviving contract for AutoCore

```
VOGPhysics_SphereQueryCollect_Ctor_Inferred(self, params):
  BaseQueryCtor(self, params)           // FUN_005eb210
  self.vtbl = PTR_FUN_009dce90
  self.collectBegin  (+0xC0) = 0
  self.collectCount  (+0xC4) = 0
  self.collectCap    (+0xC8) = 0x80000000
  return self
  // thiscall, RET 4; object size 0xD0; pool tag 0x2C at alloc sites
```

**Port tests:**

* After construct: vtbl is derived; collect empty (count 0, cap sentinel).
* Call only from sphere branches (with shape from `006c7fa0`), not AABB 0x90 path.
* Do **not** implement collect loop inside this function.
* Do **not** treat as VOG_DEBUG_STOP helper or as sphere shape.

**Verdict:** **accept** — adversarial VOG-identity / shape-merge / AABB-merge / full-loop / wrong-ABI claims **all falsified**. Runtime and product English remain open (terminal false).
