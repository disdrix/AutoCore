# Review A (reconstruction fidelity): `aa_005875c0` IntrusiveList_UnlinkByPayloadPtr_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005875c0` |
| **VA** | `0x005875c0` |
| **Canonical name (Ghidra)** | `FUN_005875c0` |
| **Proposed name** | `IntrusiveList_UnlinkByPayloadPtr_Inferred` (**High** role; product symbol absent) |
| **Prior scaffold alias** | `Named_CalleeOf_CVOGReaction_CompleteObjective_005875c0` — one caller only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_005875c0_IntrusiveList_UnlinkByPayloadPtr_Inferred.md` |
| **System** | generic intrusive list helper (missions, FX registry, etc.) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Linear search + unlink + free** of the first doubly-linked list node whose **payload pointer matches** `*key`.

List facade:

```
list {
  /* +0x00 */  // (unused here)
  /* +0x04 */  node *head;  // circular sentinel: head->next == head when empty
}
node {
  /* +0x00 */  node *next;
  /* +0x04 */  node *prev;
  /* +0x08 */  void *payload;  // compared to *param_2
}
```

Control flow:

1. `cur = *head` (first live node).
2. Loop:
   - If `cur == head` → return (not found).
   - If `cur->payload == *key` → break to unlink.
   - Else `cur = cur->next`.
3. Unlink: `cur->prev->next = cur->next`; `cur->next->prev = cur->prev`.
4. `operator_delete(cur)` — **node only**; does **not** free payload.

Decompiler shapes the search as nested `do/while` with a dead-looking `while (cur == head)` after match; net effect is **remove first matching payload node**.

**Not** map erase, not full list clear, not payload destructor.

### Callers (roles)

| Caller | Role |
|---|---|
| `FUN_004b99c0` | NDSpecialFX TeardownCore — unlink FX from external registry when bit0 set (`FUN_005875c0(&fx)` pattern; thiscall list owner often lost) |
| `CVOGReaction_CompleteObjective` `0x00533f90` | Mission complete path |
| `FUN_0052d8b0` | `ClearMissionStagingTree` — `this = char+0xCC4` list |
| `FUN_004c16d0` / `FUN_004c16f0` | Additional domain unregisters |
| `FUN_005873a0` | Sibling list op |

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005875c0` |
| Callers | `get_function_callers` (6 sites) |
| Parent duals | `A_aa_004b99c0_*`, `A_aa_0052d8b0_ClearMissionStagingTree.md` |
| Scratch note | `reviews/a_00533f90.md` (callee table) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_005875c0` |
| Function record | `docs/reconstruction/functions/aa_005875c0_FUN_005875c0.md` |

**This pass:** live decompile; callers; sibling usage. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall — ECX = list facade* (head @ +4)
void __thiscall IntrusiveList_UnlinkByPayloadPtr_Inferred(
    void *list,     // this
    void **key);    // param_2 — compare *key to node->payload
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Start at `*head` | Yes |
| Compare `node[2]` to `*param_2` | Yes |
| Not found → return | Yes |
| Bidirectional unlink | Yes |
| `operator_delete(node)` | Yes |
| No payload free / no dtor call | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Intrusive DLL remove-by-payload-pointer | **High** | body |
| Head sentinel @ `list+4` | **High** | |
| Payload @ `node+8` | **High** | |
| Frees node only | **High** | no payload delete |
| Multi-domain (mission + FX registry) | **High** | callers |
| Removes only **first** match | **High** | single unlink then return via delete |
| Product / CRT name | **Tentative** | `_Inferred` |
| Exact list owner type per caller | **Tentative** | thiscall often lost |

---

## 6. Gaps / open

1. Whether multiple nodes with same payload can exist (only first removed).
2. Ownership of payload after unlink (caller must free separately).
3. Formal registry object for FX bit0 path (`004b99c0` passes `&this` — list facade may be external).
4. Runtime not run.

**Verdict:** **accept-with-gaps** — unlink CF High; owner type names open.
