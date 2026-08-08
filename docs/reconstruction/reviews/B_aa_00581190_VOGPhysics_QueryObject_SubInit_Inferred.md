# Review B (skeptical / adversarial): `aa_00581190` VOGPhysics_QueryObject_SubInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00581190` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-027 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_00581190_VOGPhysics_QueryObject_SubInit_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity is spawn-point scaffold alias | Long `Named_CalleeOf_*CVO*` chain | **Falsified** — pure header sub-init; no spawn strings/paths in body |
| 2 | Is the full query base ctor (`005eb210`) | Parent dual merge | **Falsified** — no query vtbl `009dcde0`; no float block; no +0x80 copy; body ends at +0x38 |
| 3 | Is TtPhantom AABB ctor (`00581220`) | Nearby VA / similar refcount pattern | **Falsified** — different vtbl (`009cd99c` vs `009d45b0`); no AABB copy; RET 8 with 2 stack args vs RET 4 with 1 |
| 4 | Is sphere-collect / shape setup | Partition family guess | **Falsified** — leaf header init only; sole caller is base query ctor |
| 5 | cdecl / bare RET / no this | classification noise | **Falsified** — `MOV EAX,ECX`; stack args; **`RET 8`** |
| 6 | Has callees / not leaf | analyze misread | **Falsified** — classification `leaf`; callees empty; no CALL in body |
| 7 | Multiple direct callers | inventory noise | **Falsified** — 1 UNCONDITIONAL_CALL from `005eb21e` only |
| 8 | Mode always 2 in signature | sole call-site bleed | **Partial open** — param is free; **sole call site** hardcodes 2 (sealed); other modes not observed here |
| 9 | Vtbl `009cd99c` is query-only exclusive | sole-DATA claim | **Falsified as exclusive** — DATA also from `00507350` / `005f5760`; still correct that **this** unit writes it |
| 10 | Product class name sealed (no `_Inferred`) | Wishful RTTI | **Fails (open)** — no product plate; shared vtbl peers |
| 11 | Runtime Confirmed | Wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |
| 12 | Linked refcount always incremented | null path | **Falsified** — `JZ` skips ADD when linked_obj == 0 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 8 / ECX=self | **High** | Corrupt every construct site |
| Leaf header layout through +0x38 | **High** | Wrong base → parent overwrite mismatch |
| Sole caller = `005eb210` mode 2 | **High** | Miss only production path |
| Distinct from full query / TtPhantom / collect | **High** | Merge wrong types |
| Product class English | **Low-Med** | Doc only (`_Inferred`) |
| Mode dictionary / linked type English | **Low-Med** | Port naming only |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
// sealed CF (assembly-corrected)
self = ECX
linked_obj = [ESP+4]
mode = [ESP+8]                  // after PUSH EDI reloaded from [ESP+0xC]
self.refcount(+0x06) = 1
*self = &PTR_FUN_009cd99c
self[+0x08]=0; self[+0x0C]=linked_obj
self[+0x10]=-1; self[+0x14]=0; self[+0x18]=0
self[+0x1C]=0; self[+0x20]=0; self[+0x24]=mode
self[+0x28]=0; self[+0x30]=0; self[+0x34]=0
self[+0x38]=0x80000000
self[+0x2C]=self
if linked_obj != 0: linked_obj.refcount(+0x06)++
// RET 8; EAX = self (preserved)
```

Sibling / peer contrast (evidence only; not OWN dual):

* `FUN_005eb210` — full query base ctor (R11-008); calls this then overwrites vtbl `009dcde0`.
* `FUN_005f5760` — same provisional vtbl + near-identical fields; mode from desc; returns this; residual.
* `FUN_00507350` — dtor path temp-installs same vtbl while releasing linked object.
* `FUN_00581220` — TtPhantom AABB ctor (vtbl `009d45b0`, 0x90).

Bytes seal (`read_memory`):

```text
8B 54 24 04 8B C1 66 C7 40 06 01 00 C7 00 9C D9 9C 00   ; load args; refcount; vtbl
33 C9 3B D1 ... C7 40 10 FF FF FF FF                     ; clear; CMP linked; sentinel -1
57 8B 7C 24 0C 89 78 24 ... C7 40 38 00 00 00 80         ; mode; cap
89 40 2C 5F 74 05 66 83 42 06 01 C2 08 00 CC ...         ; self-ptr; cond ADD; RET 8; pad
```

---

## 4. Surviving contract for AutoCore

```
VOGPhysics_QueryObject_SubInit_Inferred(self, linked_obj, mode):
  self.refcount(+0x06) = 1
  self.vtbl = PTR_FUN_009cd99c          // provisional; parent may overwrite
  self.link(+0x0C) = linked_obj
  self.mode(+0x24) = mode               // production path: 2
  self.selfPtr(+0x2C) = self
  empty triad cap(+0x38) = 0x80000000
  if linked_obj: linked_obj.refcount++
  // thiscall, RET 8; leaf; EAX=self preserved
```

**Do not:** merge with full query ctor / TtPhantom / collect ctors; claim exclusive ownership of vtbl `009cd99c`; claim Runtime Confirmed; drop `_Inferred` without product plate.
