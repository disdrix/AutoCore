# Review B (skeptical / adversarial): `aa_005eb790` VOGPhysics_QueryCollect_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb790` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-037 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_005eb790_VOGPhysics_QueryCollect_Ctor_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity is spawn-point scaffold alias | `Named_CalleeOf_*CVOGSpawnPoint*CreateCreature*005eb790` | **Falsified** — pure query-collect ctor; no spawn strings/paths in body |
| 2 | Is the sphere-collect ctor (`005ebec0`) | sibling merge | **Falsified** — different VA; installs vtbl `009dce20` not `009dce90` |
| 3 | Is the base query-object ctor (`005eb210`) | parent merge | **Falsified** — calls base then overwrites vtbl + writes +0xC0 triad |
| 4 | Is sphere-shape setup (`006c7fa0`) | caller peer bleed | **Falsified** — different VA; shape is input peer at one call site only |
| 5 | Is AABB query ctor (`00581220` / 0x90) | family guess | **Falsified** — 0xD0 alloc + collect triad +0xC0; not 0x90 |
| 6 | stdcall / bare RET / no this | classification noise / undefined return | **Falsified** — `MOV ESI,ECX`; `RET 4`; `MOV EAX,ESI` |
| 7 | Does not return this / returns void | analyze `return_type undefined` | **Falsified** — `MOV EAX,ESI` before RET |
| 8 | `FUN_005eb210` is free function on params only | decompiler `FUN_005eb210(param_2)` | **Falsified** — ECX still = self at CALL; thiscall on self |
| 9 | Owns collect loop / hit processing | parent-role bleed | **Falsified** — straight-line ctor only; collect is caller vcall after return |
| 10 | Product class name sealed (no `_Inferred`) | Wishful RTTI | **Fails (open)** — vtbl DATA xrefs = ctor + dtor pair only; no `.?AV…` |
| 11 | Runtime Confirmed | Wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |
| 12 | Same class as GetObjectsInArea sphere path | mode-2 merge | **Falsified** — GetObjectsInArea uses `005ebec0`; this VA used by `004e9720`/`004e9aa0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 4 / ECX=self | **High** | Corrupt every construct site |
| Derived 0xD0 layout + vtbl `009dce20` | **High** | Wrong class → crash/wrong methods |
| Distinct from sphere collect / base / shape | **High** | Merge wrong types |
| Collect triad +0xC0 empty-init | **High** | Dtor free mismatch |
| Product class English | **Low–Med** | Doc only (`_Inferred`) |
| Full method-set / element English | **Low–Med** | Port naming only |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
// sealed CF (assembly-corrected)
self = ECX
params = [ESP+4]
FUN_005eb210(self, params)           // thiscall; base 0xC0 core
*self = PTR_FUN_009dce20             // derived vtbl (≠ 009dce90)
self[+0xC0] = 0                      // collect begin
self[+0xC4] = 0                      // collect count
self[+0xC8] = 0x80000000             // empty capacity sentinel
return self                          // EAX; RET 4
```

Sibling contrast (evidence only; not OWN dual):

* `FUN_005ebec0` — sphere collect ctor (MEGA-070); vtbl `009dce90` + triad `+0xC0`.
* `FUN_005eb210` — base query-object ctor (R11-008); no +0xC0 triad.
* `FUN_006c7fa0` — sphere **shape** setup (caller peer at `004e9720`).
* `FUN_005eb7d0` / `FUN_005eb810` — dtor / scalar dtor for this vtbl.
* `FUN_004ea350` — GetObjectsInArea uses **sphere** collect, not this VA.

Bytes seal (`read_memory`):

```text
8B 44 24 04 56 50 8B F1 E8 73 FA FF FF   ; load params; PUSH/ESI; CALL 005eb210
C7 06 20 CE 9D 00                         ; MOV [ESI], 0x9dce20
33 C0 89 86 C0 00 00 00 89 86 C4 00 00 00 ; zero +0xC0/+0xC4
C7 86 C8 00 00 00 00 00 00 80             ; [ESI+0xC8] = 0x80000000
8B C6 5E C2 04 00 CC…                     ; MOV EAX,ESI; POP ESI; RET 4; pad
```

---

## 4. Surviving contract for AutoCore

```
VOGPhysics_QueryCollect_Ctor_Inferred(self, params):
  BaseQueryCtor(self, params)            // FUN_005eb210
  self.vtbl = PTR_FUN_009dce20
  collectBegin(+0xC0) = 0
  collectCount(+0xC4) = 0
  collectCap  (+0xC8) = 0x80000000
  return self
  // thiscall, RET 4; object size 0xD0; alloc tag 0x2C at sites
```

**Port tests:**

* After construct: derived vtbl is `009dce20` (not base `009dcde0`, not sphere `009dce90`).
* Collect triad empty-init only — no hits yet.
* Do **not** implement collect loop, sphere shape, AABB 0x90 path, or GetObjectsInArea mode-2 here.
* Do **not** treat as spawn-point helper or as sphere collect ctor.
* Preserve thiscall on `FUN_005eb210` (decompiler drops this).

**Verdict:** **accept** — adversarial spawn / sphere-merge / base-merge / shape-merge / AABB-merge / wrong-ABI / void-return / collect-loop claims **all falsified**. Product English and runtime remain open (terminal false).
