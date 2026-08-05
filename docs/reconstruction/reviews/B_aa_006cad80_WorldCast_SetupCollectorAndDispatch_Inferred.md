# Review B (skeptical / adversarial): `aa_006cad80` WorldCast_SetupCollectorAndDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cad80` |
| **Canonical name** | `WorldCast_SetupCollectorAndDispatch_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-M) |
| **Counterpart** | `reviews/A_aa_006cad80_WorldCast_SetupCollectorAndDispatch_Inferred.md` |
| **System** | world / map collision cast |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Free-standing 6-stack stdcall; first arg is world | Parent verified doc omits collector this | **Falsified** — `ret 0x14` + ECX stores; wrapper builds stack collector then thiscall |
| 2 | Ray flag at `ray+8` bytes | Blind decomp `param_3+8` | **Falsified as byte-offset** — dword* arithmetic → **+0x20**; sealed by `8a 50 20` |
| 3 | Direct Havok `TtPhantom::castRay` | Terrain / wheel mix-up | **Falsified** — different VA `0x00580ed0`; this path is world vtbl+0x30 |
| 4 | Vcall is cdecl 3-arg with no world this | Decomp omits ECX | **Falsified** — `mov ecx, world` before `call [edx+0x30]` |
| 5 | Multiple CODE callers | Broad cast surface | **Open census** — xrefs show **1** CODE; DATA not claimed |
| 6 | Filter always required | | **Falsified** — null filter zeros `+8` and `+0x34` |
| 7 | Product name recovered | | **Holds open** — `_Inferred` only |
| 8 | Packet layout fully typed (start/end floats) | | **Partial** — 4 dwords + mid ptr sealed; English open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall collector + ret 0x14 | **Confirmed** | Stack smash / wrong this |
| Collector `+4/+8/+c/+34` | **Confirmed** | Wrong cast hits |
| Ray flag byte +0x20 | **Confirmed** | Wrong optional shape path |
| World vtbl+0x30 dispatch | **Confirmed** | Wrong collision backend |
| Role = map/world cast (not phantom) | **High** | Port wrong cast API |
| Filter field English | **Low** | Misnamed shape filter |
| Product symbol | **Low** | Doc only |

---

## 3. Cross-check against raw / live

```text
raw:  store ray@+4, result@+c; filter? +14 :0 @+8; flag@ray+0x20 ? filter+0x10 :0 @+0x34;
      pack ray[0..3],1,ray+0x10,0x10,extra; world.vtbl+0x30(packet, collector, 0)
live: ≡ raw; C2 14 00; FF 52 30
site: MapCollisionCtx_CastRay pushes world/ray/filter/0/result with ECX=stack collector vtbl 0x009D27D4
```

### Sentinel / sibling traps

| Trap | B position |
|---|---|
| Merge with `TtPhantom::castRay` (`0x00580ed0`) | **Reject** |
| Treat decompiler 6-arg plate as all stack | **Reject** — ECX + 5 stack |
| Assume `param_3+8` is +8 bytes | **Reject** — dword* → +0x20 |
| Invent second CODE caller without xrefs | **Reject** until proven |

---

## 4. Surviving contract for AutoCore

```
WorldCast_SetupCollectorAndDispatch(collector, world, ray, filter, extra, result):
  collector.ray    = ray
  collector.result = result
  collector.ofs08  = filter ? filter+0x14 : 0
  collector.ofs34  = (ray.byte20 != 0 && filter) ? filter+0x10 : 0
  packet = { ray[0..3], 1, &ray[4], 0x10, extra }
  world.CastVfunc30(packet, collector, 0)   // thiscall ECX=world
```

**Port tests:**

* Null filter must not read filter+0x10 / +0x14.
* Flag at ray+0x20 false → ofs34 cleared even if filter set.
* Must not call phantom cast; must use world object from map collision ctx (`ctx+0xC4`).

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Sole CODE caller MapCollisionCtx_CastRay | **Agree** (xrefs) |
| `_Inferred` product English | **Agree** leave open |
| Packet is full retail ray type | **Agree open** — only head/mid sealed here |
| Name CastTerrain-only | **Reject as sole role** — this is generic collector dispatch; terrain is one parent |

---

## 6. Open questions

1. PDB/product symbol.
2. World cast vfunc body dual.
3. Full ray / hit-result field map.
4. Runtime hit capture.

**Verdict:** **accept-with-gaps.**
