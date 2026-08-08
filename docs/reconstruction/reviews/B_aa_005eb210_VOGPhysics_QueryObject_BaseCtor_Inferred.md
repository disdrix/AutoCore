# Review B (skeptical / adversarial): `aa_005eb210` VOGPhysics_QueryObject_BaseCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb210` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-008 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_005eb210_VOGPhysics_QueryObject_BaseCtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity is spawn-point scaffold alias | Long `Named_CalleeOf_*CVOGSpawnPoint*` chain | **Falsified** — pure query base ctor; no spawn strings/paths in body |
| 2 | Is the full sphere-collect ctor (`005ebec0`) | Parent dual merge | **Falsified** — no write to `+0xC0` triad; no derived vtbl `009dce90` |
| 3 | Is sphere-shape setup (`006c7fa0`) | Partition sphere hint | **Falsified** — different VA; this builds 0xC0 query core + params copy |
| 4 | Is AABB query ctor (`00581220` / 0x90) | Same family guess | **Falsified** — callers are 0xD0 collect ctors; size/layout differ |
| 5 | stdcall / bare RET / no this | classification noise / undefined return | **Falsified** — `MOV ESI,ECX`; `RET 4`; `MOV EAX,ESI` |
| 6 | Does not return this / returns void | analyze `return_type undefined` | **Falsified** — `MOV EAX,ESI` before RET |
| 7 | `FUN_00581190` is free function on params only | decompiler `FUN_00581190(param_2[1],2)` | **Falsified** — ECX still = self at CALL; thiscall on self |
| 8 | `FUN_005eb040` takes only params+8 (no dest) | decompiler drop | **Falsified** — `LEA ECX,[ESI+0x80]` before CALL |
| 9 | Collect triad at +0xC0 is owned here | derived-field bleed | **Falsified** — body ends at +0xBF max write; +0xC0 is derived |
| 10 | Product class name sealed (no `_Inferred`) | Wishful RTTI | **Fails (open)** — vtbl DATA xrefs = this ctor only; no `.?AV…` |
| 11 | Runtime Confirmed | Wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |
| 12 | `DAT_009dcddc` is integer handle | type guess | **Falsified** — `MOVSS` float load/store; value ~1e30 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 4 / ECX=self | **High** | Corrupt every construct site |
| Base 0xC0 layout + vtbl | **High** | Wrong base → derived crash |
| Shared by both collect ctors | **High** | Miss sibling path |
| Distinct from derived / shape / AABB | **High** | Merge wrong types |
| Product class English | **Low–Med** | Doc only (`_Inferred`) |
| Full params / field English | **Low–Med** | Port naming only |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
// sealed CF (assembly-corrected)
self = ECX
params = [ESP+4]
FUN_00581190(self, params[1], 2)     // thiscall; mode 2
triadA(+0x3C) = {0, 0, 0x80000000}
triadB(+0x48) = {0, 0, 0x80000000}
self[+0x2C] = self
*self = &PTR_FUN_009dcde0
float8(+0x60) zero; [+0x6C]=[+0x7C]=DAT_009dcddc  // ~1e30
self[+0x28] = params[0]
self[+0x14] = &self[+0x60]
self[+0x54] = vcall(*(self+0xC), slot +0x14)
FUN_005eb040(self+0x80, params+0x20) // 16 dwords
return self                           // EAX; RET 4
```

Sibling contrast (evidence only; not OWN dual):

* `FUN_005ebec0` — derived sphere collect ctor (MEGA-070); vtbl `009dce90` + triad `+0xC0`.
* `FUN_005eb790` — sibling collect ctor; vtbl `009dce20` + triad `+0xC0`.
* `FUN_006c7fa0` — sphere **shape** setup (not this VA).
* `FUN_00581220` — AABB-path query ctor (0x90).
* `FUN_004ea350` — parent `CVOGPhysicsUtils::GetObjectsInArea`.

Bytes seal (`read_memory`):

```text
56 57 8B 7C 24 0C 8B 47 04 6A 02 50 8B F1 E8 …   ; push/save; CALL 00581190
… C7 06 E0 CD 9D 00 …                            ; MOV [ESI], 0x9dcde0
… 8D 8E 80 00 00 00 … E8 …                       ; LEA ECX,[ESI+0x80]; CALL 005eb040
8B C6 5E C2 04 00 CC…                            ; MOV EAX,ESI; POP ESI; RET 4; pad
```

---

## 4. Surviving contract for AutoCore

```
VOGPhysics_QueryObject_BaseCtor_Inferred(self, params):
  SubInit(self, params[1], mode=2)       // FUN_00581190
  triadA(+0x3C) = empty(0x80000000)
  triadB(+0x48) = empty(0x80000000)
  self.selfPtr(+0x2C) = self
  self.vtbl = PTR_FUN_009dcde0
  floatBlock(+0x60) zeros; W = ~1e30
  self[+0x28] = params[0]
  self[+0x14] = &floatBlock
  self[+0x54] = vcall(params-linked object)
  copy params[+0x20 .. +0x5F] -> self[+0x80 .. +0xBF]
  return self
  // thiscall, RET 4; base core 0xC0; derived add +0xC0 collect → 0xD0
```

**Port tests:**

* After construct: base vtbl is `009dcde0`; no derived collect triad yet.
* Both sphere and sibling collect ctors call this first, then overwrite vtbl and set `+0xC0`.
* Do **not** implement collect loop, shape setup, or AABB 0x90 path here.
* Do **not** treat as spawn-point helper or as derived collect ctor.
* Preserve thiscall on `FUN_00581190`/`FUN_005eb040` (decompiler drops this).

**Verdict:** **accept-with-gaps** — adversarial identity / derived-merge / shape-merge / AABB-merge / wrong-ABI / decompiler-thiscall claims **all falsified**. Product English, full field map, residual callees, and runtime remain open (terminal false).
