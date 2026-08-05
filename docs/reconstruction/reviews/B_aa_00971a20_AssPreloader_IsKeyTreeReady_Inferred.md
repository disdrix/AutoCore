# Review B (skeptical / adversarial): `aa_00971a20` AssPreloader_IsKeyTreeReady_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971a20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-E) |
| **Counterpart** | `reviews/A_aa_00971a20_AssPreloader_IsKeyTreeReady_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure predicate / no side effects | **Falsified** — always calls `FUN_00971480` drain (may log/delete already-loaded) |
| 2 | Decompiler void / no formals | **Falsified** — dual `C2 08 00`; AL 0/1 |
| 3 | recurse=0 means “fully ready including deps” | **Falsified** — recurse=0 only checks tree membership; deps only when recurse!=0 **and** cache+0x64 |
| 4 | Dep failure requires both not-tree and not-present | **Confirmed** — OR of present saves a non-tree dep; both false → 0 |
| 5 | `param_2 == end` compares raw key to end | **Falsified** — find overwrites key slot with node*; decompiler reuse |
| 6 | ECX is NDResourceCache | **Falsified** — tree@+0x10, cache back-ptr@+0x110; ProcessKeyRingStep passes preloader from `cache+0x6c` |
| 7 | Scaffold assManager name is product | **Rejected** — parent-seed alias; plate is assPreloader via nested logs |
| 8 | Same as IsKeyPresent | **Falsified** — tree membership vs NestedHash present; complementary gates in ProcessKeyRingStep |
| 9 | Recursive dep uses recurse=1 | **Falsified** — forced **0** (no transitive dep-of-dep walk in one call) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 8 + AL | **High** | Wrong port ABI / stack balance |
| Tree find miss → 0 | **High** | False ready |
| recurse / +0x64 dep policy | **High** | Infinite recurse or skip deps |
| Drain side-effect | **High** | Port as pure would drop drain |
| Product English | **Low** | Naming only |
| Nested free contracts | **Med** | Mislabel drain/find/fill |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// ProcessKeyRingStep (recurse=0):
//   !cache_present && !tree_ready → enqueue / wait
//   tree_ready alone can advance without NestedHash present
// SweepTrackedAssets / AssManager paths: secondary probe
// assPreloader.cpp plate via FUN_00971480 log strings
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 341 B hex seals SEH, both RET 8 exits, dep page map, inlined present gates.

---

## 4. Surviving contract for AutoCore

```
// Port as thiscall readiness probe with entry drain:
bool IsKeyTreeReady(AssPreloader* self /*ECX*/, const void* key, bool recurse) {
  DrainPending(self);                          // FUN_00971480 — do not omit
  auto node = MapExactFind(self->tree@+0x10, key);
  if (node == self->tree_end@+0x14) return false;
  if (!recurse || !*(cache@self+0x110 + 0x64)) return true;
  for (dep : FillDeps(key)) {
    if (!IsKeyTreeReady(self, dep, false)
        && !IsKeyPresent(cache, dep))
      return false;
  }
  return true;
}
// Do not deep-recurse deps (forced recurse=0).
// Do not treat as NestedHash present-check alone.
// Pair with W36-E peer IsKeyPresent + W35-A ProcessKeyRingStep.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/tree/dep/present-OR/drain. Residual product plate + unowned nested duals + runtime → **accept-with-gaps**.
