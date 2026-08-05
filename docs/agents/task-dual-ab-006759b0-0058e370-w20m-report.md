# OWN-ONLY dual agent report — W20-M

| Field | Value |
|---|---|
| Agent | W20-M |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x006759b0`, `0x0058e370` |
| Tools | Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## VA `0x006759b0` — StdList_BuyNode_Dword

| Field | Value |
|---|---|
| Ghidra | `FUN_006759b0` |
| Canonical | `StdList_BuyNode_Dword` (**Inferred**) |
| Body | `0x006759b0`–`0x006759d6` (39 B) |
| Role | `operator_new(0xC)` list node: link0 / link1 / `*value`; returns node* in EAX |
| ABI | `__stdcall` `ret 0xc` |
| Callers | 40+ (Auth, sound queue, UI, map, …) — **not** Auth-only |
| Live ≡ raw | Yes |
| **Verdict** | **accept** |

### Artifacts

- `docs/reconstruction/raw/aa_006759b0_FUN_006759b0.md`
- `docs/reconstruction/raw/aa_006759b0_FUN_006759b0.annotated.md`
- `docs/reconstruction/reconstructed-exact/StdList_BuyNode_Dword.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_006759b0.cpp`
- `docs/reconstruction/functions/aa_006759b0_StdList_BuyNode_Dword.md`
- `docs/reconstruction/functions/aa_006759b0_FUN_006759b0.md`
- `docs/reconstruction/reviews/A_aa_006759b0_StdList_BuyNode_Dword.md`
- `docs/reconstruction/reviews/B_aa_006759b0_StdList_BuyNode_Dword.md`

---

## VA `0x0058e370` — CVOGObject_SetGfxBodyLink_Mode1AndTarget

| Field | Value |
|---|---|
| Ghidra | `FUN_0058e370` |
| Canonical | `CVOGObject_SetGfxBodyLink_Mode1AndTarget` (**Inferred**) |
| Body | `0x0058e370`–`0x0058e398` (40 B) |
| Role | If `this+0x914` (gfxBody) and `gfxBody+0x78` (packet) non-null: mode=`1`, packet+4=`target` |
| ABI | `__thiscall` `ret 4` |
| Caller | `FUN_004b73c0` @ `0x004b7408` only |
| Live ≡ raw | Yes |
| **Verdict** | **accept** |

### Artifacts

- `docs/reconstruction/raw/aa_0058e370_FUN_0058e370.md`
- `docs/reconstruction/raw/aa_0058e370_FUN_0058e370.annotated.md`
- `docs/reconstruction/reconstructed-exact/CVOGObject_SetGfxBodyLink_Mode1AndTarget.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0058e370.cpp`
- `docs/reconstruction/functions/aa_0058e370_CVOGObject_SetGfxBodyLink_Mode1AndTarget.md`
- `docs/reconstruction/functions/aa_0058e370_FUN_0058e370.md`
- `docs/reconstruction/reviews/A_aa_0058e370_CVOGObject_SetGfxBodyLink_Mode1AndTarget.md`
- `docs/reconstruction/reviews/B_aa_0058e370_CVOGObject_SetGfxBodyLink_Mode1AndTarget.md`

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / partition map edits.
- Did not write duals for non-owned helpers (`004b73c0`, `0058f780`, `00480350`, `0043fe60`, etc.).
- Parent-seed names `Named_CalleeOf_Auth_AuthServer_006759b0` and long `Named_CalleeOf_…_Cli_0058e370` retained as **alias** plates only; canonical names preferred.
- Decompiler gap on `006759b0`: typed `void` but EAX returns node* (byte + caller evidence).
- Prior 2026-07-23 scaffolds superseded by this seal (raw bodies preserved; live sections appended).
