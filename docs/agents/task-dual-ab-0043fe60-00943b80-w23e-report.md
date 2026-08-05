# OWN-ONLY dual agent report — W23-E

| Field | Value |
|---|---|
| Agent | W23-E |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x0043fe60`, `0x00943b80` |
| Tools | Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`); also bounds/callers/callees/xrefs via HTTP bridge |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## VA `0x0043fe60` — StdList_Incsize

| Field | Value |
|---|---|
| Ghidra | `FUN_0043fe60` |
| Canonical | `StdList_Incsize` (**High** inferred — MSVC `_Incsize` + plate string) |
| Body | `0x0043fe60`–`0x0043fece` |
| Role | MSVC `std::list` size bump: max `0x3fffffff` gate → `"list<T> too long"` throw, else `_Mysize += count` |
| ABI | **ECX**=count, **EDX**=list*, plain **`RET`** |
| Callers | 18+ including `StdList_PushPayloadNode` (`00480350`), Auth send, UI |
| Callees | `FUN_00401a40`, `_CxxThrowException`, `basic_string` |
| Live ≡ raw | Yes |
| **Verdict** | **accept** |

### Artifacts

- `docs/reconstruction/raw/aa_0043fe60_FUN_0043fe60.md`
- `docs/reconstruction/raw/aa_0043fe60_FUN_0043fe60.annotated.md`
- `docs/reconstruction/reconstructed-exact/StdList_Incsize.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0043fe60.cpp`
- `docs/reconstruction/functions/aa_0043fe60_StdList_Incsize.md`
- `docs/reconstruction/functions/aa_0043fe60_FUN_0043fe60.md`
- `docs/reconstruction/reviews/A_aa_0043fe60_StdList_Incsize.md`
- `docs/reconstruction/reviews/B_aa_0043fe60_StdList_Incsize.md`

---

## VA `0x00943b80` — Client_FlushWorldObjectState_Inferred

| Field | Value |
|---|---|
| Ghidra | `FUN_00943b80` |
| Canonical | `Client_FlushWorldObjectState_Inferred` (**Probable**) |
| Body | `0x00943b80`–`0x00943dae` |
| Role | Client world-object/container flush on teardown & sector reconnect; optional hard flag for UI vtbl + list insert |
| ABI | **EDI**=client, stack `char flag`, **`RET 4`** |
| Callers | TeardownGameplaySession, Net_InitNetworking_sector, `00943fb0`, `009492d0`, `008153b0`, `009466f0` (flag=1) |
| Callees | 17 including `004962b0`, `00933370`, `004bae00`, `00415e90`×2, … |
| Live ≡ raw | Yes |
| **Verdict** | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_00943b80_FUN_00943b80.md`
- `docs/reconstruction/raw/aa_00943b80_FUN_00943b80.annotated.md`
- `docs/reconstruction/reconstructed-exact/Client_FlushWorldObjectState_Inferred.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_00943b80.cpp`
- `docs/reconstruction/functions/aa_00943b80_Client_FlushWorldObjectState_Inferred.md`
- `docs/reconstruction/functions/aa_00943b80_FUN_00943b80.md`
- `docs/reconstruction/reviews/A_aa_00943b80_Client_FlushWorldObjectState_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00943b80_Client_FlushWorldObjectState_Inferred.md`

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / partition map edits.
- Did not write artifacts for non-owned helpers (`00401a40`, `00403600` twin, `004962b0`, `00933370`, `00415e90`, `00944b20`, …).
- Named clean plates preferred; FUN_* aliases updated to point at sealed CF.
- Prior raw bodies preserved; W23-E live seal sections appended only.
- Ghidra accessed via HTTP `127.0.0.1:8089` (MCP stdio bridge not registered in this session’s tool host).
