# Review B (skeptical / adversarial): `aa_00984c70` AssPackManager_AddDirectoryTree_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984c70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-E) |
| **Counterpart** | `reviews/A_aa_00984c70_AssPackManager_AddDirectoryTree_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure ECX-thiscall with `this` = pack manager | **Falsified** — bytes push **ECX as path** into `009839b0`; pack is **stack** formal (EBP) |
| 2 | Decompiler `unaff_EDI` is noise / dead | **Partially open** — bytes **PUSH EDI** into `00984910` as mode; never set in body → caller/register formal gap, not pure dead store |
| 3 | Function extracts/compacts pack | **Falsified** — only collect leaves + add-file; compact is `00985010` (W32-E) |
| 4 | Expands globs / `@` lists | **Falsified** — that is `00984340`; this unit only dir recurse + add |
| 5 | Has static game callers | **Open risk** — **0 xrefs**; likely offline tool entry |
| 6 | Name is PDB product | **Careful** — `_Inferred` from nested `assPackManager.cpp` plate + CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Collect-then-add CF | **High** | Wrong port structure |
| ECX path + stack pack | **High** | Wrong ABI |
| Nested AssPackManager add-file | **High** | Mis-family |
| EDI mode | **Low/Open** | Wrong add-file type |
| Product wrapper English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Full body 182 B read_memory (W33-E append)
// PUSH ECX; PUSH &listing; CALL 009839b0; ADD ESP,8
// if EAX >= 0: for leaf:
//   string copy; ECX=c_str; PUSH 0; PUSH 0; PUSH 1; PUSH EDI; PUSH EBP; CALL 00984910
// FUN_00431ae0; XOR EAX,EAX; RET
// Xrefs: none
// Nested 00984910: vog_LogMessage(...assPackManager.cpp...)
```

Live decompile 2026-07-29 ≡ scaffold CF. Body end `C3` @ `0x00984d25`.

---

## 4. Surviving contract for AutoCore

```
// Port as free helper (or static), not naive ECX=this pack method:
int AddDirectoryTree(const char* dirPath /*ECX*/, AssPackManager* pack /*stack*/) {
  StringVector leaves;
  if (DirRecurseCollectLeafPaths(dirPath, &leaves) >= 0) {
    for (leaf : leaves)
      pack->AddFile(leaf, /*mode from EDI — preserve register ABI or surface formal*/, 1, 0, 0);
  }
  return 0;
}
// Do not invent gameplay callers. Pair with Open/Compact pack duals.
// Preserve flags 1,0,0 until 00984910 is dual-sealed.
```

---

## 5. Verdict

Adversarial pass confirms A on CF/AssPackManager family/ECX-path+stack-pack (bytes). Residual EDI mode + 0 xrefs + nested add-file plate → **accept-with-gaps**.
