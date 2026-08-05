# Review B (skeptical / adversarial): `Emitter_ReleaseToFreelist_Inferred` / `FUN_005be310` @ `0x005be310`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005be310` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-R) |
| **Counterpart** | `reviews/A_aa_005be310_Emitter_ReleaseToFreelist_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX is NDSpecialFX host / list owner | **Falsified** — callers `mov ecx, 0x00B454FC` (global freelist) |
| 2 | Function `operator_delete`s the emitter | **Falsified** — freelist push only after teardown; no delete in this body |
| 3 | `FUN_005bbc50` is called with freelist head as this | **Falsified** — bytes `mov ecx, esi` (node) before call |
| 4 | Plain RET / no stack cleanup | **Falsified** — `ret 4` |
| 5 | Only HostTick calls this | **Falsified** — ClearChildLists + FUN_004a34f0 ×7 |
| 6 | Same freelist as motion slots (`DAT_00b036c0`) | **Falsified** — emitter freelist is `DAT_00b454fc` |
| 7 | Product name retail | **Overstated** — `_Inferred` |
| 8 | Runtime verified | **Open** |
| 9 | Null-check protects teardown | **Falsified** — teardown runs before null gate; gate only covers freelist push |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Freelist push via dword0 | **High** | Pool corruption |
| Global freelist head | **High** | Wrong free pool |
| ret 4 ABI | **High** | Stack corruption |
| Teardown this = node | **High** | Crash / wrong free |
| Product English | **Medium** | Docs only |
| Teardown child internals | **Open** | W30-S residual |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes

```
head = freelist* (DAT_00b454fc at sites)
node = stack arg
FUN_005bbc50(this=node)     // heavy teardown
if node:
  node->next = *head
  *head = node
ret 4
```

Entry `56 8B 74 24 08 57 8B F9 8B CE E8 …`. Exit `5F 5E C2 04 00`. Call site pattern `50/56 B9 FC 54 B4 00 E8 …`.

---

## 4. Surviving contract for AutoCore

```
// ECX = freelist head* (global DAT_00b454fc in retail call sites)
// stack Emitter*; ret 4
// MUST run body teardown (FUN_005bbc50) before freelist push
// MUST NOT operator_delete the emitter here — recycle via freelist
// HostTick owns list-node unlink/delete of the +0x1E0 wrapper after kill
// Distinct from ObjectMotion_SlotReleaseToFreelist (DAT_00b036c0)
```

Do not treat ECX as the NDSpecialFX host. Do not merge with list unlink/delete. Do not invent free inside this unit.

---

## 5. Verdict

Adversarial pass **confirms** A: emitter teardown + freelist release with global head → **accept**.
