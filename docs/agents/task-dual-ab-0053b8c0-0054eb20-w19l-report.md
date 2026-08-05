# OWN-ONLY dual agent report — W19-L

| Field | Value |
|---|---|
| Agent | W19-L |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x0053b8c0`, `0x0054eb20` |
| Tools | Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## VA `0x0053b8c0` — CNDHash_ReclaimAll_NonOwning_009cefdc

| Field | Value |
|---|---|
| Ghidra | `FUN_0053b8c0` |
| Canonical | `CNDHash_ReclaimAll_NonOwning_009cefdc` (**Inferred**) |
| Body | `0x0053b8c0`–`0x0053b8ff` (64 B, bare `ret`) |
| Role | Non-owning full-bucket reclaim: stamp `009cefdc`, freelist-push `+0x20`, clear heads; **no** value delete |
| Caller | FreeBuckets non-owning `0x0053b880` @ `0x0053b88a` only |
| Live ≡ raw | Yes |
| **Verdict** | **accept** |

### Artifacts

- `docs/reconstruction/raw/aa_0053b8c0_FUN_0053b8c0.md`
- `docs/reconstruction/raw/aa_0053b8c0_FUN_0053b8c0.annotated.md`
- `docs/reconstruction/reconstructed-exact/CNDHash_ReclaimAll_NonOwning_009cefdc.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0053b8c0.cpp`
- `docs/reconstruction/functions/aa_0053b8c0_CNDHash_ReclaimAll_NonOwning_009cefdc.md`
- `docs/reconstruction/functions/aa_0053b8c0_FUN_0053b8c0.md`
- `docs/reconstruction/reviews/A_aa_0053b8c0_CNDHash_ReclaimAll_NonOwning_009cefdc.md`
- `docs/reconstruction/reviews/B_aa_0053b8c0_CNDHash_ReclaimAll_NonOwning_009cefdc.md`

---

## VA `0x0054eb20` — SkillElementTypeMap_InsertOrFind

| Field | Value |
|---|---|
| Ghidra | `FUN_0054eb20` |
| Canonical | `SkillElementTypeMap_InsertOrFind` (**Inferred**) |
| Body | `0x0054eb20`–`0x0054ebd7` (three `ret 8`) |
| Role | `std::map` insert-or-find: int type-id → factory*; node 0x18 / isnil +0x15; equal key no rewrite |
| Caller | `SkillElementFactory_RegisterCatalog` `0x0054a640` × **39** |
| Callees | `FUN_0054de50` (insert+rebalance), `FUN_005a2850` (predecessor) |
| Live ≡ raw | Yes |
| **Verdict** | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_0054eb20_FUN_0054eb20.md`
- `docs/reconstruction/raw/aa_0054eb20_FUN_0054eb20.annotated.md`
- `docs/reconstruction/reconstructed-exact/SkillElementTypeMap_InsertOrFind.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0054eb20.cpp`
- `docs/reconstruction/functions/aa_0054eb20_SkillElementTypeMap_InsertOrFind.md`
- `docs/reconstruction/functions/aa_0054eb20_FUN_0054eb20.md`
- `docs/reconstruction/reviews/A_aa_0054eb20_SkillElementTypeMap_InsertOrFind.md`
- `docs/reconstruction/reviews/B_aa_0054eb20_SkillElementTypeMap_InsertOrFind.md`

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / partition map edits.
- Did not write artifacts for non-owned helpers (`0054de50`, `005a2850` owned by W19-N).
- Named clean plates preferred over prior auto scaffolds; FUN_*.cpp aliases updated to match sealed CF.
