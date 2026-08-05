# Review B (skeptical / adversarial): `aa_007300c0` PalToolNoMap_Host0x34_MeshBuildUpload_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007300c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-J) |
| **Counterpart** | `reviews/A_aa_007300c0_PalToolNoMap_Host0x34_MeshBuildUpload_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall | **Falsified** — stack host; `RET 4` |
| 2 | Always returns 0 | **Falsified** — failure path returns `0xFFFFFFFF` |
| 3 | Dual material slots like 00731130 | **Falsified** — single material at **+0x24** only |
| 4 | Scaffold `Gfx_PalToolMaterialNoMap` complete | **Careful** — plate real; omits mesh upload / Host0x34 role |
| 5 | `piRam00000010` is real absolute RAM | **Falsified as product meaning** — decompiler stack alias; do not port as null-page IO |
| 6 | Multiple callers | **Falsified** — sole xref `0073c9f5` in HostPtrTable12 bootstrap |
| 7 | Host size free | **Mostly sealed** — caller `new(0x34)`; fields through +0x2c fit |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall host* + RET 4 + SEH | **High** | Wrong ABI |
| Material +0x24 | **High** | Wrong layout |
| Counts +0x1c/+0x20; +0x2c=4 | **High** | Wrong mesh meta |
| Return 0/-1 | **High** | Wrong error model |
| Second path stack recovery | **Medium** | Incomplete second mesh port |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- Body bounds `get_function_by_address`: `007300c0`–`007308b7` (2040 B).
- Prologue SEH: `6A FF 68 B6 1E 9B 00 64 A1 … 81 EC E4 00 00 00`.
- Epilogue: `81 C4 F0 00 00 00 C2 04 00`.
- Xref: one unconditional call from `0073c9f5` (W35-E slot6).
- Shares plate family with `aa_00731130` but different host size and upload depth.

---

## 4. Surviving contract for AutoCore

```
// Port as stdcall mesh build/upload (not thiscall):
int BuildPalToolNoMapMesh(void *host /* size 0x34 */) {
  // SEH; build local meshes; bind PalToolMaterialNoMap.fx at host+0x24
  // host+0x20 = tri/vert meta; host+0x1c = index meta; host+0x2c = 4
  // VB format 0x152; Lock flag 0x800; attach IB/VB into host+0x14 path
  // return 0 ok, -1 fail
}
// Do not treat decompiler piRam* as absolute addresses.
// Pair with HostPtrTable12 slot6 inline multi-vtbl ctor (W35-E).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, single material slot, counts, returns, sole caller. Residual second-path decompiler alias + product English + helper depth → **accept-with-gaps**.
