# Dual A/B report — W29-D OWN `aa_007b65d0` + `aa_0043c2e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-D  
**Scope:** VAs `0x007b65d0`, `0x0043c2e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave29.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007b65d0` AssManager_ReleaseOwnedResolvers_Inferred | **accept-with-gaps** — EBX this + dual-arm CF + assManager strings sealed; nested list helpers residual |
| `aa_0043c2e0` Map_TreeInsertAndRebalance_Val12_EsiBuy | **accept-with-gaps** — EDI map + `ret 0x10` + ESI buy + Val12 RB CF sealed; product demangle / rotate duals residual |

---

## VA `0x007b65d0` — sealed facts

1. **Body:** `0x007b65d0`–`0x007b66a3` exclusive (**211** B / `0xD3`; pad `CC` then `FUN_007b66b0` @ `0x007b66b0`).
2. **ABI:** **EBX=this**; no stack formals; frame `push ecx` (local key) + `push esi`; plain **`ret`**.
3. **Semantics:** Dtor body for object with optional resolver interfaces at **`+0x08`** and **`+0x0c`**.  
   - **Arm A (`+8`):** `FUN_00423e00` with `ECX=*DAT_00d1f058` (EAX still holds key from entry); scalar-delete `(1)`; null slot; up to **20** first-element erases on string vector `*DAT_00d1f1fc` (elem **0x1c**) via `FUN_0044d4e0`.  
   - **Arm B (`+0xc`):** key on stack; container = `*DAT_00d1f058 + 0x58` (GuardedVector); `FUN_0043e5b0` find; miss → `vog_LogMessage(assManager.cpp, 0x27b, 3, "Removing resolver not found")`; hit → `FUN_0043c550` EraseFirstEqual (W28-C); scalar-delete; null.
4. **Strings:** path `0x00a9e930`, msg `0x00a9e888` (sealed `read_memory`).
5. **Classification:** worker — callees unowned except `FUN_0043c550` dualed W28-C.
6. **Callers (3):** `FUN_004239a0` (scalar deleting dtor), `FUN_007b66b0` (complete dtor), `FUN_00939fd0`; xrefs also `0x009c3050`.
7. **Name:** `AssManager_ReleaseOwnedResolvers_Inferred` (Ghidra `FUN_007b65d0`; **Inferred** from file path + message).
8. **Decompile ≡ bytes** for dual-arm CF; arm-A key-in-EAX for `FUN_00423e00` is call-site inference (unowned helper residual).  
   Full hex: `518b430885c056746a8b0d58f0d100e81cd8c6ff8b4b0885c974068b016a01ff1055578b3dfcf1d100c7430800000000bd140000008b770485f674308b4f082bceb893244992f7e903d1c1fa048bcac1e91f03ca894c240c7412568d5424105257e8aa6ec9ff8b3dfcf1d10083ed0175c45f5d8b430c85c074568b3558f0d100894424048d44240483c658508bc6e84d7fc8ff84c0751b6888e8a9006a03687b0200006830e9a900e843071e0083c410eb0a8d4c240451e8c45ec8ff8b4b0c85c974068b116a01ff12c7430c000000005e59c3`

### Gaps

- Product/PDB class English; resolver interface type.  
- Unowned `FUN_00423e00` / `FUN_0043e5b0` / `FUN_0044d4e0`.  
- Side-table identity of `DAT_00d1f1fc` (max-20 first-erase policy).  
- Runtime / concurrent remove under CS.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007b65d0_AssManager_ReleaseOwnedResolvers_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007b65d0_AssManager_ReleaseOwnedResolvers_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007b65d0_FUN_007b65d0.md` |
| Annotated | `docs/reconstruction/raw/aa_007b65d0_FUN_007b65d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssManager_ReleaseOwnedResolvers_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007b65d0.cpp` |
| Function | `docs/reconstruction/functions/aa_007b65d0_FUN_007b65d0.md` |
| Function named | `docs/reconstruction/functions/aa_007b65d0_AssManager_ReleaseOwnedResolvers_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_007b65d0.md` |

---

## VA `0x0043c2e0` — sealed facts

1. **Body:** `0x0043c2e0`–`0x0043c45f` exclusive (**383** B / `0x17F`; pad `CC`).
2. **ABI:** Map in **EDI**; 4 stack formals `(outIt, addLeft, where, value*)`; SEH `LAB_009bc919`; `add esp,0x50; **ret 0x10**`. Decompiler listed 3 args — **bytes win**.
3. **Semantics:** Always-insert Val12 RB node: throw if `size > 0x15555553`; buy via **`FUN_0046c6c0`** (ESI=value*, color 0, W28-T); `size++`; link first/left/right + sentinel extremes; rebalance while parent red; paint root black; `*outIt = n`.
4. **Layout:** head `+0x04`, size `+0x08`; node value `+0x0c` (12 B), color `+0x18`, isnil `+0x19` (`new(0x1c)`).
5. **Rotates:** `FUN_00446b10` (L), `FUN_0040b910` (R) — **alternate** pair vs twin `aa_0044a8c0` (`00573170`/`00418c10`).
6. **Classification:** worker — multi-caller insert kernel.
7. **Callers (6 / 23 xrefs):** `FUN_0043be60`, `FUN_00445680`, `FUN_0046c450`, `FUN_0046c5c0`, `FUN_0046f6e0`, `FUN_0046f810`.
8. **Name:** `Map_TreeInsertAndRebalance_Val12_EsiBuy` (Ghidra `FUN_0043c2e0`; **Inferred** structural).
9. **Decompile ≡ bytes** for insert/link/rebalance CF; 4th arg + ESI buy sealed by epilogue + buy site.  
   Entry: `64a1000000006aff6819c99b00506489250000000083ec44817f0854555515`  
   Epilogue: `83c450c21000`

### Gaps

- Product/MSVC demangle per map instantiation (six parents).  
- Buynode null OOM path.  
- Full dual of rotate helpers `00446b10` / `0040b910`.  
- Runtime golden.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043c2e0_Map_TreeInsertAndRebalance_Val12_EsiBuy.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043c2e0_Map_TreeInsertAndRebalance_Val12_EsiBuy.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c2e0_FUN_0043c2e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c2e0_FUN_0043c2e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12_EsiBuy.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c2e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043c2e0_FUN_0043c2e0.md` |
| Function named | `docs/reconstruction/functions/aa_0043c2e0_Map_TreeInsertAndRebalance_Val12_EsiBuy.md` |
| Scratch | `docs/reconstruction/tmp/a_0043c2e0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007b65d0` | Asset/resolver entry dtor must use **EBX this**, clear **both** `+8` and `+0xc` through manager list remove + scalar delete. Arm B miss must log `assManager.cpp:0x27b` / `"Removing resolver not found"`. Do not drop GuardedVector erase at manager **`+0x58`** or the max-20 first-erase of the **0x1c** string vector at `*DAT_00d1f1fc`. Nested `FUN_00423e00` / find helpers remain residual. |
| `0043c2e0` | Val12 always-insert kernel: map in **EDI**, **`ret 0x10`**, buy via **`FUN_0046c6c0` ESI value**, max size **`0x15555553`**, rotates **`00446b10`/`0040b910`**. Do not merge with `aa_0044a8c0` (different rotates) or `0x0051c1c0` (stack buy + ECX this). Parents own key walk — this unit never compares keys. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` / structural names only.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit structs).  
- Cross-links: W28-C EraseFirstEqual callee; W28-T ESI buynode; W27-P EsiBuy twin.
