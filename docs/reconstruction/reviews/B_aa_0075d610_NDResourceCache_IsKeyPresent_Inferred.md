# Review B (skeptical / adversarial): `aa_0075d610` NDResourceCache_IsKeyPresent_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075d610` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-E) |
| **Counterpart** | `reviews/A_aa_0075d610_NDResourceCache_IsKeyPresent_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void` / bare signature | **Falsified** — dual `C2 04 00`; EAX 0/1 sealed |
| 2 | Stack formal is key value (int) not pointer | **Falsified** — `MOV EBX,[ESP+8]` feeds FindIterator which requires **key\***; callers pass string-object / slot addresses |
| 3 | Present means “any node hit” | **Falsified** — null **value@+0x0C** → 0 (empty slot / tombstone style) |
| 4 | ECX is AssPreloader | **Falsified** — map end@+0x08 NestedHash layout; ProcessKeyRingStep passes `DAT_00d1f050` cache |
| 5 | Inserts on miss | **Falsified** — sole callee is find-only `0044e8c0` |
| 6 | Scaffold VOG_DEBUG name is product | **Rejected** — parent-seed alias only |
| 7 | Name claims PDB “NDResourceCache” English | **Careful** — structural from DAT plate + NestedHash host duals; `_Inferred` only |
| 8 | Same as LookupOrCreate | **Falsified** — no create/factory; pure predicate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 4 + 0/1 | **High** | Wrong port ABI |
| end@+8 + value@+0xC gates | **High** | False positive present |
| Nested FindIterator register ABI | **High** | Broken call if reimplemented wrong |
| Product method English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// ProcessKeyRingStep (W35-A):
//   if !NDResourceCache_IsKeyPresent(cache, slot) && !IsKeyTreeReady(preloader, slot, 0)
//     → enqueue deps / wait
// LoadNextChildAsset / FX preload:
//   skip force-load when present already
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 48 B hex seals both `RET 4` paths.
Callee dual: W21-N HashMap_FindIterator (EDI/EBX + ret 4).

---

## 4. Surviving contract for AutoCore

```
// Port as thiscall predicate (not free function with cache on stack only):
bool IsKeyPresent(NDResourceCache* cache /*ECX*/, const void* key) {
  auto it = HashMap_FindIterator(cache, key); // register ABI of find
  return it != cache->end && it->value != nullptr;
}
// Do not treat null value as present.
// Do not invent insert-on-miss.
// Pair with W21-N FindIterator + W35-B cache ctor NestedHash@+0.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/gates/sole-callee. Residual product plate + runtime → **accept-with-gaps**.
