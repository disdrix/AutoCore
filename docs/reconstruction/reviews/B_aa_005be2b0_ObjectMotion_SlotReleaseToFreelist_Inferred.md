# Review B (skeptical / adversarial): `ObjectMotion_SlotReleaseToFreelist_Inferred` / `FUN_005be2b0` @ `0x005be2b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005be2b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-I) |
| **Counterpart** | `reviews/A_aa_005be2b0_ObjectMotion_SlotReleaseToFreelist_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX is motion host / list owner | **Falsified** — both callers `mov ecx, 0x00B036C0` (global freelist) |
| 2 | Function deletes the slot | **Falsified** — freelist push only; list tick owns `operator_delete` of **list node** after this |
| 3 | `FUN_004b0bd0` does real work | **Falsified** — empty body (`ret` only) |
| 4 | Plain RET / no stack cleanup | **Falsified** — `ret 4` |
| 5 | Only one caller | **Falsified** — SlotListTick + host teardown |
| 6 | Child@+0x8 is list prev/next | **Falsified** — nested freelist-compatible child payload; cleared after push |
| 7 | Product name retail | **Overstated** — `_Inferred` |
| 8 | Runtime verified | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Freelist push order (child then node) | **High** | Double-free / leak of nested child |
| Global freelist head | **High** | Wrong free pool / corruption |
| ret 4 ABI | **High** | Stack corruption |
| Empty dtor stub | **High** | Over-porting nonexistent cleanup |
| Product English | **Medium** | Docs only |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes

```
head = freelist* (DAT_00b036c0 at sites)
if node.child@+8:
  nop_dtor(child); freelist_push(child); node.child=0
nop_dtor(node); freelist_push(node)
ret 4
```

Entry `56 8B 74 24 08 57 8B F9 8B 4E 08 …`. Exit `5F 5E C2 04 00`. Call site pattern `53/50 B9 C0 36 B0 00 E8 …`.

---

## 4. Surviving contract for AutoCore

```
// ECX = freelist head* (global DAT_00b036c0 in retail call sites)
// stack SlotNode*; ret 4
// MUST freelist-push nested +0x8 child before parent
// MUST NOT operator_delete here — list tick deletes list wrapper after return
// FUN_004b0bd0 is empty — do not invent resource teardown inside it
```

Do not treat ECX as motion host. Do not merge with list unlink/delete.

---

## 5. Verdict

Adversarial pass **confirms** A: freelist release helper with global head and optional child push → **accept**.
