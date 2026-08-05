# Review B (skeptical / adversarial): `aa_00494700` Host_EnsureRegionCellOwned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00494700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-C) |
| **Counterpart** | `reviews/A_aa_00494700_Host_EnsureRegionCellOwned_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a full host rebuild/resize | **Falsified** — no free of grid array; only per-cell owned ensure; dims unchanged (contrast W30-Q `0x004941b0`) |
| 2 | cdecl both args on stack | **Falsified** — `MOV EDI,ECX`; `RET 4` one stack formal |
| 3 | Always allocates every cell | **Falsified** — occupied path only `FUN_004bd6f0` |
| 4 | Alloc size is Elem0x28 (0x28) | **Falsified** — `push 0x5E0`; ctor is ListTrackedObj `FUN_004becb0` |
| 5 | Eviction is in-place reuse without dtor | **Falsified** — null `+0x24` then `FUN_004be2a0` + `operator_delete` |
| 6 | Ghidra noreturn aborts outer loops | **Falsified** — bytes continue y/x increments and set busy=1 |
| 7 | Unrelated to static culling | **Falsified** — caller `FUN_004951d0` logs `"Static culling"` then calls this |
| 8 | Flag `+0x53` is permanent disable | **Falsified** — cleared at entry, set at exit (session/busy) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 4 | **High** | Stack corruption |
| 0x28 cell formula + region bounds | **High** | OOB / wrong cell |
| Create 0x5E0 ListTrackedObj | **High** | Size/type mismatch |
| Evict = CompleteDtor + delete | **High** | Leak / double free |
| Product host/ctx names | **Low** | Naming only |
| Pressure policy English | **Med** | Wrong eviction port |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_004951d0:
FUN_0076cf00("Static culling");
FUN_00494b80(...);
FUN_00494700(ctx);   // this unit
// then per-cell cull helpers

// ListTrackedObj lifecycle:
ctor FUN_004becb0 ↔ complete dtor FUN_004be2a0 (W30-P)
// stored at Elem0x28.owned@+0x24 (W29-F frees via same dtor)
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Epilogue `RET 4` + busy flag sealed by hex.

---

## 4. Surviving contract for AutoCore

```
// Port as region ENSURE (not rebuild):
void Host_EnsureRegionCellOwned(Host* host, Context* ctx) {
  host->busy_0x53 = 0;
  for x,y in host region AABB:
    cell = grid[y * dimX + x]; // stride 0x28
    if (!cell.owned) {
      obj = new ListTrackedObj(0x5E0); // FUN_004becb0(cell,0)
      obj->ctx_0x5d4 = ctx;
      place(obj,x,y); populate(obj);
      cell.owned = obj;
      maybe_evict_pressure(); // CompleteDtor+delete victim
    } else {
      mru_touch(obj);
    }
  host->busy_0x53 = 1;
}
// Do not confuse with Host_RebuildElem0x28ArrayFromMap (W30-Q).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/region/create/evict. Residual product English + pressure policy → **accept-with-gaps**.
