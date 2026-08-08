# Review B (skeptical / adversarial): `aa_00581220` TtPhantom_CtorFromAabbDesc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00581220` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-037) |
| **Counterpart** | `reviews/A_aa_00581220_TtPhantom_CtorFromAabbDesc_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This **is** `GetObjectsInArea` itself | **Falsified** — parent is `0x004ea350`; this is leaf ctor only (167 B, no query loop) |
| 2 | Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_*` | **Falsified** — no `VOG_DEBUG_STOP` in body; parent AABB-fail path has that string, not this VA |
| 3 | `__cdecl` / no stack cleanup | **Falsified** — epilogue **`RET 4`** + ECX this |
| 4 | `void` return (decompiler) | **Falsified** — entry `MOV EAX,ECX`; callers `MOV ESI/store,EAX` |
| 5 | hkAabbPhantom product type (string only) | **Not sealed as product name** — `hkAabbPhantom` string exists in binary but **no** RTTI/plate ties this vtbl; class sealed via **TtPhantom** castRay plate + layout instead |
| 6 | Mode-2 sphere path ctor | **Falsified** — mode-2 uses `FUN_006c7fa0` / `FUN_005ebec0` (size `0xd0`), not this `0x90` path |
| 7 | Performs broadphase query itself | **Falsified** — leaf stores only; query register is `FUN_0055ff20` (separate VA) |
| 8 | Product ctor demangle without `_Inferred` | **Fails gate** — no ctor plate; keep **`_Inferred`** |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 4 + EAX=this | **Confirmed** | Stack imbalance / lost handle |
| Leaf straight-line CF | **Confirmed** | Invented query logic in port |
| Alloc size 0x90 + tag at +4 | **Confirmed** | Heap corruption |
| Overlap list at +0x80/+0x84 | **Confirmed** | CastRay / GetObjects iterate wrong |
| AABB 8 dwords from src+0x20 | **Confirmed** | Wrong query volume |
| Class = TtPhantom (via castRay) | **High** | Mis-family port |
| Method English “CtorFromAabbDesc” | **High inferred** | Doc only if wrong |
| Full vtbl English | **Low** | Doc only |
| Runtime | **Open** | Behavioral drift |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23  ≡  live decompile 2026-08-05  ≡  clean TtPhantom_CtorFromAabbDesc_Inferred.cpp

8B C1                    MOV EAX,ECX
66 C7 40 06 01 00        MOV word [EAX+6],1
...
C7 00 B0 45 9D 00        MOV [EAX],009d45b0
...
8B 4C 24 04              MOV ECX,[ESP+4]
... copy [ECX+20h .. +3Ch] → [EAX+60h .. +7Ch]
8B 09                    MOV ECX,[ECX]
89 48 28                 MOV [EAX+28h],ECX
C2 04 00                 RET 4

Body end: 0x005812c6; pad CC; dtor twin FUN_005812d0 @ 0x005812d0
Xrefs: 6 UNCONDITIONAL_CALL (GetObjectsInArea mode-1, vehicle, creature, AI, factory)
```

Reject ports that:

- Name this as `GetObjectsInArea` or `VOG_DEBUG_STOP` helper.
- Implement query/filter loops inside the ctor.
- Use cdecl without popping the desc arg.
- Confuse with mode-2 `0xd0` shape phantom ctors (`005ebec0` family).
- Drop `_Inferred` without a new plate/RTTI seal.
- Claim runtime Confirmed without Launcher golden.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: TtPhantom constructed from AABB descriptor (0x90 object).
// Not the GetObjectsInArea manager — parents alloc, construct, register, iterate.

sealed class TtPhantom
{
    // +0x00 vtbl; +0x06 refcount; +0x24 type=2; +0x28 lead;
    // +0x2c self; +0x60 aabb[8]; +0x80 overlap list / +0x84 count / +0x88 cap
    public TtPhantom(in AabbDesc desc) { /* field init only; no world query */ }
}

// Call pattern (GetObjectsInArea mode-1):
//   var p = Alloc(0x90); p.SizeTag = 0x90;
//   TtPhantom_CtorFromAabbDesc(p, stackAabbDesc);
//   WorldRegisterPhantom(world, p);  // FUN_0055ff20
//   foreach hit in p.OverlapList ...
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/callers/class family. Remaining gaps are vtbl English, descriptor field names, and runtime → **accept-with-gaps**.
