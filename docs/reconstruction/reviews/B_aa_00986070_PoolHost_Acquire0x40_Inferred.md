# Review B (skeptical / adversarial): `aa_00986070` PoolHost_Acquire0x40_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00986070` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-R) |
| **Counterpart** | `reviews/A_aa_00986070_PoolHost_Acquire0x40_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `FUN_00456780(0)` is the shrink size | **Falsified** — non-empty path loads `size-1` into ECX before call |
| 2 | Function is pure / no context (no EBX) | **Falsified** — all host accesses via `unaff_EBX`; sole caller preloads EBX from `DAT_00d1f624` |
| 3 | Always allocates (no freelist) | **Falsified** — empty check on +0x14/+0x18; pop `*(end-4)` when non-empty |
| 4 | `FUN_004406e0` is unrelated / no-op | **Falsified** — always called with EAX=EBX, ESI=&result; pushes onto vector @+4 |
| 5 | Object size is not 0x40 | **Falsified** — `push 0x40; call operator_new`; ctor `FUN_0074e380` writes through +0x3C |
| 6 | Multiple independent callers | **Falsified** — single xref `0x00756352` in HostBase_EnsureAuxPtrs |
| 7 | Freelist and track vector are the same | **Falsified** — freelist begin/end @+0x14/+0x18; track push uses host+4/+8/+0xC |
| 8 | This is a freelist *release* (return to pool) | **Falsified** — pops freelist or news; never writes into freelist end-grow as primary path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Acquire pop-or-new role | **High** | Wrong aux install |
| EBX pool host ABI | **High** | Silent wrong host |
| 0x40 + FUN_0074e380 | **High** | Wrong object |
| Track push always | **High** | Missed registration |
| Dual-vector layout | **High** | Wrong port structure |
| Track vector English | **Med** | Wrong ownership model |
| Product demangle | **Low** | Naming only |
| Release path | **Open** | Incomplete pool story |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + caller

```
// HostBase_EnsureAuxPtrs (0x00756320):
//   if (flags & 1) {
//     ebx = *DAT_00d1f624;
//     host[+4] = FUN_00986070();  // EBX contract
//   }
// Entry: 6A FF 68 D3 F9 9A 00 ... (SEH)
// Exit:  8B C7 5F 5E 64 89 0D ... 83 C4 10 C3  @ 0x00986124
// FUN_0074e380: g_flOne @+0; zeros; FUN_0043fdf0 @+0x14 → StdList_AllocSentinel_0xC
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 skeleton; body hex corrects shrink size and seals push.

---

## 4. Surviving contract for AutoCore

```
// Port as pool acquire (not release):
obj = PoolHost_Acquire0x40(pool /* *DAT_00d1f624 */);
// Must: if freelist empty → new(0x40)+ctor else pop last + shrink size-1;
//       always push obj onto track vector @pool+4; return obj (0 on OOM).
// Retail call: load EBX=pool before call; no stack args.
// Do not invent product class names; keep _Inferred.
// Do not treat as freelist release. Find release VA separately.
// HostBase: only when (flags & 1); store at host+4.
```

---

## 5. Verdict

Adversarial pass confirms A on EBX ABI, pop-or-new, track push, sole caller, 0x40 ctor. Residual product English + release path + track-vector role → **accept-with-gaps**.
