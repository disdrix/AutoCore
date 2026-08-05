# Review A (reconstruction fidelity): `aa_0040d4b0` HardpointList_FindById

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d4b0` |
| **VA** | `0x0040d4b0`–`0x0040d4e2` (body; `ret 4`) |
| **Canonical name** | `HardpointList_FindById` (inferred; Ghidra `FUN_0040d4b0`) |
| **Plate alias** | `Named_CalleeOf_Named_phyCPConnection_0040d4b0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0040d4b0_HardpointList_FindById.md` |
| **System** | physics hardpoint / connection-point registry + special-event probes |
| **Evidence pass** | Live decompile + `read_memory` full leaf; parent dual `aa_0044af00`; Respawn/Teleport callers with ids `0x23` / `0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tiny **intrusive list find-by-id** leaf:

1. If `*registry == 0` → return **null**.
2. `sentinel = *(*registry + 0xC)`; walk circular list via `node = *node`.
3. Match when `*(node[2] + 8) == id` (id at payload object `+0x8`).
4. On hit: return **`node + 2`** (pointer to the payload object* slot / node payload header).
5. On full cycle back to sentinel → **null**.

No mutation. No logging. Used as hardpoint / connection-point lookup from:

- `Phy_CPConnection_AssertConnectionPoint` (`owner+0x64` registry)
- `ClientSpecialEvent_Respawn_Update` probes **0x23** (35) and **0**
- TeleportIn and other attach/probe callers

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040d4b0_FUN_0040d4b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d4b0_FUN_0040d4b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0040d4b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d4b0_FUN_0040d4b0.md` |
| Parent dual | `reviews/A_aa_0044af00_Phy_CPConnection_AssertConnectionPoint.md` |
| Live | `read_memory` entire leaf; leaf (no callees) |

**Three-rep:** present.

---

## 3. Signature (image-sealed)

```c
// __thiscall  ECX = registry* (often owner+0x64)
// stack: int id
// ret 4
// returns void** / node+2 or NULL
void *HardpointList_FindById(void *registry, int id);
```

| Item | Evidence | Conf |
|---|---|---|
| `ret 4` | bytes `c2 04 00` | **High** |
| ECX registry | decomp thiscall | **High** |
| Match `*( *(node+8) + 8 ) == id` | `mov esi,[eax+8]; cmp [esi+8],edx` | **High** |
| Return `node+8` bytes ≡ `puVar2+2` | `add eax,8` | **High** |
| Empty / miss → EAX 0 | `xor eax,eax` | **High** |

### List node sketch

```
node+0x00 : next*
node+0x08 : payload*   // id lives at payload+0x8
// return node+0x08 address (pointer-to-payload-slot), not payload*
```

Parent assert path: `obj = **(returned)` i.e. dereference once more for the object*.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Null registry root → 0 | **Yes** | **High** |
| Sentinel at `*root+0xc` | **Yes** | **High** |
| Walk `*node` until sentinel | **Yes** | **High** |
| Id compare at payload+8 | **Yes** | **High** |
| Hit → node+8 | **Yes** | **High** |
| Pure leaf | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Find-by-id list walk | **High** | full body sealed |
| Return is node payload slot (`+8`), not payload | **High** | parent `mov esi,[eax]` |
| Used for hardpoint / CP ids | **High** | callers + parent dual |
| Id **0x23** = hardpoint 35 (INC) | **High** (caller strings) | Respawn dual |
| Product STL/container name | **Open** | residual |
| Full registry type at owner+0x64 | **Tentative** | parent residual |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Product name (std list vs custom intrusive).
2. Complete node size / prev link (only next used here).
3. Full id enum beyond observed 0 / 0x23 / connection ids.
4. Whether all callers treat return as `T**` consistently (parent assert does).

**Verdict:** **accept-with-gaps**
